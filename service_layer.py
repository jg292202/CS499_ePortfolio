import logging

class AnimalService:
    def __init__(self, db):
        self.db = db
        self.logger = logging.getLogger("AnimalService")
        
    def get_animals(self, filter_type):
        try:
            query = self._build_query(filter_type)
            self.logger.info(f"Query built: {query}")
            results = self.db.read(query)
            return results
        except Exception as e:
            self.logger.error(f"Service error: {e}")
            return []
            
    def _build_query(self, filter_type):
        if filter_type == "water":
            return {"animal_type": "Dog",
                    "breed": {"$in": ["Labrador Retriever Mix",
                                     "Chesapeake Bay Retriever"]}}
        if filter_type == "mountain":
            return {"animal_type": "Dog",
                   "breed": {"$in": ["German Shepherd",
                                      "Border Collie"]}}
        if filter_type == "disaster":
             return {"animal_type": "Dog",
                    "breed": {"$in": ["Bloodhound",
                                      "Doberman Pinscher"]}}
        return {}
            
            
    def validate_filter(self, filter_type):
        allowed = {"water", "mountain", "disaster", "reset"}
        if filter_type not in allowed:
            self.logger.warning(f"Invalid filter: {filter_type}")
            return "reset"
        return filter_type
    
    # DataTable input validation
    def validate_table_filter(self, filter_query):
        # Dash filter_query is None when no filter is applied
        if filter_query is None or filter_query.strip() == "":
            return ""
        # Simple validation to prevent dangerous characters
        forbidden = [";", "{", "}", "$", "&&", "||"]
        if any(f in filter_query for f in forbidden);
            self.logger.warning(f"Invalid table filter expression: {filter_query}")
            return ""
        return filter_query


        
        
 