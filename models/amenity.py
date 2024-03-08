#!/usr/bin/python3
"""this module for class amenity"""
from models.base_model import BaseModel


class Amenity(BaseModel):
    """class : Amenity to store more data"""
    name = ""

    def __init__(self, *args, **kwargs):
        """__init__ methoud to super cls"""
        super().__init__(*args, **kwargs)
