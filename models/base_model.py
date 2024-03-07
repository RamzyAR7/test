#!/usr/bin/python3
"""
this module for base class
"""
from datetime import datetime
import models
import uuid


class BaseModel:
    """BaseModel class the parant"""
    def __init__(self, *args, **kwargs):

        if kwargs:
            for key, value in kwargs.items():
                if key == '__class__':
                    continue
                if key == "created_at" or key == "updated_at":
                    value = datetime.fromisoformat(value)
                setattr(self, key, value)
        else:
            self.id = str(uuid.uuid4())
            self.created_at = datetime.now()
            self.updated_at = datetime.now()
            models.storage.new(self)

    def __str__(self):
        return f"[{type(self).__name__}] ({self.id}) {self.__dict__}"

    def save(self):
        self.updated_at = datetime.now()
        models.storage.save()

    def to_dict(self):
        info_dict = self.__dict__
        info_dict['__class__'] = type(self).__name__
        #update formate
        info_dict['created_at'] = self.created_at.isoformat()
        info_dict['updated_at'] = self.updated_at.isoformat()

        return info_dict
