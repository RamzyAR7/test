#!/usr/bin/python3
"""
this module is for console
"""
import cmd
import json
from models.base_model import BaseModel
from models import storage


class HBNBCommand(cmd.Cmd):
    """ this class is for console"""
    #lst = ["quit", "EOF"]
    def do_create(self, args):
        """Creates a new instance of BaseModel."""
        if not args:
            print("** class name missing **")
            return
        try:
            obj = eval(args)()
            storage.save()
            print(obj.id)
        except NameError:
            print("** class doesn't exist **")

    def do_show(self, args):
        """Prints the string representation of an instance"""
        args_list = args.split()
        if not args_list:
            print("** class name missing **")
            return
        try:
            class_name = args_list[0]
            if  not class_name == "BaseModel":
                print("** class doesn't exist **")
                return
            if len(args_list) < 2:
                print("** instance id missing **")
                return
            instances = storage.all()
            instance_id = args_list[1]
            key = class_name + "." + instance_id
            if key not in instances:
                print("** no instance found **")
                return
            print(instances[key])
        except Exception as e:
            print(e)

    def do_destroy(self, args):
        """ Deletes an instance based on the class name and id """
        args_list = args.split()

        if not args_list:
            print("** class name missing **")
            return
        class_name = args_list[0]
        if class_name != "BaseModel":
            print("** class doesn't exist **")
            return
        if len(args_list) < 2:
            print("** instance id missing **")
            return

        try:
            objs = storage.all()
            obj_id = args_list[1]
            key = class_name + '.' + obj_id

            if key not in objs:
                print("** no instance found **")
                return

            objs.pop(key)
            storage.save()
        except Exception as ex:
            print(ex)

    def do_all(self, args):
        """Prints all string representation of all instances based or not on the class name."""

        if args and args != "BaseModel":
            print("** class doesn't exist **")
            return

        objs = storage.all()
        instances_list = []
        for value in objs.values():
            instances_list.append(str(value))
        print(instances_list)

    def do_update(self, args):
        """ Updates an instance based on the class name and id"""
        args_list = args.split()
        if not args_list:
            print("** class name missing **")
            return
        try:
            class_name = args_list[0]
            if  not class_name == "BaseModel":
                print("** class doesn't exist **")
                return
            if len(args_list) < 2:
                print("** instance id missing **")
                return
            instances = storage.all()
            instance_id = args_list[1]
            key = class_name + "." + instance_id
            if key not in instances:
                print("** no instance found **")
                return
            if len(args_list) < 3:
                print("** attribute name missing **")
                return
            if len(args_list) < 4:
                print("** value missing **")
                return
            if len(args_list) > 4:
                return
            if args_list[2] in ["id", "created_at", "updated_at"]:
                return
            attr_name = args_list[2]
            attr_value = json.loads(args_list[3])

            if isinstance(attr_value, str) and attr_value.isdigit():
                attr_value = int(attr_value)

            setattr(instances[key], attr_name, attr_value)
            storage.save()

        except Exception as e:
            print(e)

    def emptyline(self):
        """Do nothing on empty line."""
        pass

    def do_EOF(self, args):
        """EOF command to exit the program"""
        return True

    def do_quit(self, args):
        """Quit command to exit the program"""
        return True


if __name__ == "__main__":
    console = HBNBCommand()
    console.prompt = "(hbnb) "
    console.cmdloop()