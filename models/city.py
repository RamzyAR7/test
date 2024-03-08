#!/usr/bin/python3
"""this module for class city"""
from models.base_model import BaseModel


class City(BaseModel):
    """class : City to store more data"""
    state_id = ""
    name = ""

    def __init__(self, *args, **kwargs):
        """__init__ methoud to super cls"""
        super().__init__(*args, **kwargs)
