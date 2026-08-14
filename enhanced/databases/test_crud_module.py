#test_crud_module.py

import unittest
from CRUD_Python_Module2 import AnimalShelter

# ---------------------------------------------------------
# Fake in-memory database + collection for testing
# ---------------------------------------------------------
class FakeCollection:
    def __init__(self):
        self.data = []
        
    def insert_one(self, doc):
        doc["_id"] = len(self.data) + 1
        self.data.append(doc)
        return type("Result", (), {"inserted_id": doc["_id"]})
    
    def find(self, query, projection=None):
        results = []
        for doc in self.data:
            match = all(doc.get(k) == v for k, v in query.items())
            if match:
                if projection:
                    projected = {k: doc.get(k) for k in projection if projection[k] == 1}
                    results.append(projected)
                else:
                    results.append(doc)
        return FakeCursor(results)
                                 
    def update_one(self, query, update):
        modified = 0
        for doc in self.data:
            if all(doc.get(k) == v for k, v in query.items()):
                for k, v in update["$set"].items():
                    doc[k] = v
                modified = 1
                break
        return type("Result", (), {"modified_count": modified})

    def update_many(self, query, update):
        modified = 0
        for doc in self.data:
            if all(doc.get(k) == v for k, v in query.items()):
                for k, v in update["$set"].items():
                    doc[k] = v
                modified += 1
        return type("Result", (), {"modified_count": modified})

    def delete_one(self, query):
        deleted = 0
        for doc in list(self.data):
            if all(doc.get(k) == v for k, v in query.items()):
                self.data.remove(doc)
                deleted = 1
                break
        return type("Result", (), {"deleted_count": deleted})

    def delete_many(self, query):
        deleted = 0
        for doc in list(self.data):
            if all(doc.get(k) == v for k, v in query.items()):
                self.data.remove(doc)
                deleted += 1
        return type("Result", (), {"deleted_count": deleted})
                                 
                                 
    def sort(self, field, direction):
        return sorted(self.data, key=lambda d: d.get(field), reverse=(direction == -1))
    
                                 
    # simple aggregation that only supports $sum and $group
    def aggregate(self, pipeline):
        results = {}
        for doc in self.data:
            key = doc.get("animal_type")
            results[key] = results.get(key, 0) + 1
        return [{"_id": k, "count": v} for k, v in results.items()]
                                 
# Fake database wrappers that mimics MongoDB's clent["db"]["collection'] behavior                                 

class FakeDatabase:
    def __getitem__(self, name):
        return FakeCollection()

class FakeDB:
    def __getitem__(self, name):
        return FakeDatabase()

# A fake cursor is needed since MongoDB returns a cursor and FakeCollection does not.
class FakeCursor(list):
    def sort(self, field, direction):
        return sorted(self, key=lambda d: d.get(field), reverse=(direction == -1))
                                 
# ---------------------------------------------------------
#                       Unit Tests
# ---------------------------------------------------------
                                 
class TestCRUDModule(unittest.TestCase):
    
    def setUp(self):
        self.db = FakeDB()
        self.shelter = AnimalShelter(self.db)
                                 
        # Seed the database with fake data
        self.shelter.collection.data = [
            {"animal_type": "Dog", "name": "Rex", "age": 5, "intake_date": "2024-01-01"},
            {"animal_type": "Dog", "name": "Buddy", "age": 3, "intake_date": "2024-02-01"},
            {"animal_type": "Cat", "name": "Whiskers", "age": 2, "intake_date": "2024-03-01"},
        ]
                                 
    #*********************************
    #            CREATE
    #*********************************
    def test_create(self):
        result = self.shelter.create({"animal_type": "Dog", "name": "Max"})
        self.assertTrue(result)
                                 
    #*********************************
    #            READ
    #*********************************
    def test_read(self):
        dogs = self.shelter.read({"animal_type": "Dog"})
        self.assertEqual(len(dogs), 2)
                                 
    #*********************************
    #           PROJECTION
    #*********************************
    def test_projection(self):
        proj = {"name": 1, "_id": 0}
        names = self.shelter.read({"animal_type": "Dog"}, proj)
        self.assertEqual(list(names[0].keys()), ["name"])
                                 
                                 
    #*********************************
    #           UPDATE ONE
    #*********************************
    def test_update_one(self):
        modified = self.shelter.update({"name": "Rex"}, {"age": 6})
        self.assertEqual(modified, 1)
                                 
    #*********************************
    #           UPDATE MANY
    #*********************************
    def test_update_many(self):
        modified = self.shelter.update({"animal_type": "Dog"}, {"age": 10}, multiple=True)
        self.assertEqual(modified, 2)

    #*********************************
    #           DELETE ONE
    #*********************************
    def test_delete_one(self):
        deleted = self.shelter.delete({"name": "Rex"})
        self.assertEqual(deleted, 1)

    #*********************************
    #           DELETE MANY
    #*********************************
    def test_delete_many(self):
        deleted = self.shelter.delete({"animal_type": "Dog"}, multiple=True)
        self.assertEqual(deleted, 2)

    #*********************************
    #           SORTED READ
    #*********************************
    def test_sorted_read(self):
        sorted_dogs = self.shelter.read_sorted({"animal_type": "Dog"}, "intake_date", ascending=False)
        self.assertEqual(sorted_dogs[0]["name"], "Buddy")

    #*********************************
    #          AGGREGATION
    #*********************************
    def test_aggregation(self):
        results = self.shelter.aggregate([
            {"$group": {"_id": "$animal_type", "count": {"$sum": 1}}}
        ])
        self.assertTrue(any(r["_id"] == "Dog" for r in results))

    #*********************************
    # VALIDATION: FORBIDDEN OPERATOR
    #*********************************
    def test_forbidden_operator(self):
        with self.assertRaises(ValueError):
            self.shelter.read({"$where": "evil"})

    #**************************************
    # VALIDATION: NESTED FORBIDDEN OPERATOR
    #**************************************
    def test_nested_forbidden_operator(self):
        with self.assertRaises(ValueError):
            self.shelter.read({"$and": [{"age": 5}, {"$eval": "evil"}]})
                                 
if __name__ == "__main__":
    unittest.main()