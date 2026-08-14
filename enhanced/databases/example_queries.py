#example_queries.py

# Demonstrates advanced database queries using the enhanced CRUD module.
# Includes filtering, projection, sorting, and aggregation pipelines.

from pymongo import MongoClient
from CRUD_Python_Module2 import AnimalShelter

# ---------------------------------------------------------
#   Establish database connection (dependency injection)
# ---------------------------------------------------------
client = MongoClient("mongodb://localhost:27017")
shelter = AnimalShelter(client)

# ---------------------------------------------------------
#              Basic READ with filtering
# ---------------------------------------------------------
print("\n==== Filter: Find all dogs ====")
dogs = shelter.read({"animal_type": "Dog"})
print(f"Found {len(dogs)} dogs")

# ---------------------------------------------------------
#                  READ with projection
# ---------------------------------------------------------
print("\n==== Projection: Only name and breed ====")
projection = {"name": 1, "breed": 1, "_id": 0}
dog_names = shelter.read({"animal_type": "Dog"}, projection)
# Only print the first 5 dogs found 
for d in dog_names[:5]:
    print(d)
    
# ---------------------------------------------------------
#                     Sorted READ
# ---------------------------------------------------------
print("\n==== Sorted: Dogs by intake_date descending ====")
sorted_dogs = shelter.read_sorted({"animal_type":  "Dog"}, "intake_date", ascending=False)
# Only print the first 5 dogs found with intake_date ascending
for d in sorted_dogs[:5]:
    print(d.get("name"), d.get("intake_date"))
    

# ---------------------------------------------------------
#           Aggregation: Count animals by type
# --------------------------------------------------------- 
print("\n==== Aggregation: Count animals by type ====")
pipeline = [
    {"$group": {"_id": "$animal_type", "count": {"$sum": 1}}},
    {"$sort": {"count": -1}}
]
counts = shelter.aggregate(pipeline)
for c in counts:
    print(c)
    
    
# ---------------------------------------------------------
#           Aggregation: Average age by breed
# --------------------------------------------------------- 
print("\n==== Aggregation: Average age by breed ====")
pipeline_avg_age = [
    {"$match": {"animal_type": "Dog"}},
    {"$group": {"_id": "$breed", "avg_age": {"$avg": "$age"}}},
    {"$sort": {"avg_age": 1}}
]
avg_age_results = shelter.aggregate(pipeline_avg_age)
for r in avg_age_results[:10]:
    print(r)
    
    
# ---------------------------------------------------------
#   Nested validation test (Should produce ValueError)
# --------------------------------------------------------- 
print("\n==== Validation Test: Forbidden operator ====")
try:
    shelter.read({"$where": "this.age > 5"})
except ValueError as e:
    print("Validation caught forbidden operator:", e)
    

# ---------------------------------------------------------
#   Nested validation test inside list/dict
# --------------------------------------------------------- 
print("\n==== Validation Test: Nested forbidden operator ====")
try:
    shelter.read({"$and": [{"age": {"$gt": 5}}, {"$eval": "evil"}]})
except ValueError as e:
    print("Nested validation caught forbidden operator:", e)
    