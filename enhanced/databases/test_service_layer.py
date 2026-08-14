import unittest
from service_layer import AnimalService

# Fake database class for testing
class FakeDB:
    def read(self, query):
        
        # Return a predictable result for testing
        return [{"animal_type": "Dog", "breed": "Beagle"}]
    
class TestAnimalService(unittest.TestCase):
    
    def setUp(self):
        self.service = AnimalService(FakeDB())
        
    def test_validate_filter_valid(self):
        self.assertEqual(self.service.validate_filter("water"), "water")
        self.assertEqual(self.service.validate_filter("mountain"), "mountain")
        self.assertEqual(self.service.validate_filter("disaster"), "disaster")
        self.assertEqual(self.service.validate_filter("reset"), "reset")
        
    def test_validate_filter_invalid(self):
        self.assertEqual(self.service.validate_filter("INVALID"), "reset")
        self.assertEqual(self.service.validate_filter("123"), "reset")
        
    def test_get_animals(self):
        results = self.service.get_animals("water")
        self.assertEqual(len(results), 1)
        self.assertEqual(results[0]["breed"], "Beagle")
        
if __name__ == "__main__":
    unittest.main()