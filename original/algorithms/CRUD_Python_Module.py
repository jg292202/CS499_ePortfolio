# CRUD_Python_Module.py

from pymongo import MongoClient 
from bson.objectid import ObjectId
from pymongo.errors import PyMongoError

class AnimalShelter(object): 
    """ CRUD operations for Animal collection in MongoDB """ 

    def __init__(self): 
        # Initializing the MongoClient. This helps to access the MongoDB 
        # databases and collections. This is hard-wired to use the aac 
        # database, the animals collection, and the aac user. 
        # 
        # Connection Variables 
        # 
        USER = 'aacuser' 
        PASS = 'aacuserPa55w0rD' 
        HOST = 'localhost' 
        PORT = 27017 
        DB = 'aac' 
        COL = 'animals' 
        # 
        # Initialize Connection 
        #
        try:
            self.client = MongoClient(
                host=HOST,
                port=PORT,
                username=USER,
                password=PASS,
                authSource="admin"
            ) 
            # Try accessing target database and collection:
            self.database = self.client[DB] 
            self.collection = self.database[COL] 
        except PyMongoError as e:
            print(f"Error connecting to MongoDB: {e}")
            self.collection = None

    # Create a method to return the next available record number for use in the create method
    
    
    
    ########################### CREATE ###################################        
    def create(self, data):
        """ Insert a document into the collection.
        param data: dict containing key/value pairs
        return: True if successful, otherwise False. """
        if data is None:
            raise Exception("Nothing to save, because data parameter is empty")
        try:
            # Try to insert one data object into the collection:
            result = self.collection.insert_one(data)
            return True if result.inserted_id else False
        except PyMongoError as e:
            print(f"Insert failed: {e}")
            return False         
        
    ########################### READ ###################################               
    def read(self, query):
        """ Query documents from the collection.
        param query: dict containing key/value lookup
        return: list of documents if successful, empty list otherwise """
        try:
            # convert the results of the find() function into a list for easier use
            docs = self.collection.find(query)
            return list(docs)
        except PyMongoError as e:
            print(f"Query failed: {e}")
            return []
        
        ########################### UPDATE ###################################               
    def update(self, query, update_data, multiple=False):
        """ Update document(s) in the collection.
        param query: dict filter for documents to update
        param update_data: dict of fields to update
        param multiple: bool - True for update_many, false for update_one
        return: number of documents modified. """
        try:
            if multiple:
                result = self.collection.update_many(query, {"$set": update_data})
            else:
                result = self.collection.update_one(query, {"$set": update_data})
            return result.modified_count
        
        except PyMongoError as e:
            print(f"Update failed: {e}")
            return 0
        
        ########################### DELETE ###################################               
    def delete(self, query, multiple=False):
        """ Delete document(s) from the collection.
        param query: dict filter for documents to delte.
        param multiple: bool, True for delete_many, False for delete_one
        return: number of documents delted """
        try:
            if multiple:
                result = self.collection.delete_many(query)
            else:
                result = self.collection.delete_one(query)
            return result.deleted_count
        except PyMongoError as e:
            print(f"Delete failed: {e}")
            return 0