#!/usr/bin/python3
"""
this module for serializes and deserializes
"""
import json
import os
from models.base_model import BaseModel
from models.user import User
from models.amenity import Amenity
from models.city import City
from models.place import Place
from models.review import Review
from models.state import State


class FileStorage:
    """this class for serializes and deserializes"""
    __file_path = "file.json"
    __objects = {}

    def all(self):
        return self.__objects

    def new(self, obj):
        key = f"{type(obj).__name__}.{obj.id}"
        self.__objects[key] = obj

    def save(self):
        #update dict
        js_dict = {}
        for key, value in self.__objects.items():
            js_dict[key] = value.to_dict()
        #from dict to file
        with open(self.__file_path, 'w', encoding='utf-8') as file:
            json.dump(js_dict, file)

    def reload(self):
        #from file to dict
        if os.path.isfile(self.__file_path):
            with open(self.__file_path, 'r', encoding='utf-8') as file:
                js_dict = json.load(file)
                for key, value in js_dict.items():
                    self.__objects[key] = eval(value['__class__'])(**value)
        else:
            return
