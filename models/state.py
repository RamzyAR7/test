#!/usr/bin/python3
"""this module for class state"""
from models.base_model import BaseModel


class State(BaseModel):
    """class : state to store more data"""
    name = ""

    def __init__(self, *args, **kwargs):
        """__init__ methoud to super cls"""
        super().__init__(*args, **kwargs)
