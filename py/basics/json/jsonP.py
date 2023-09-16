from json import JSONEncoder
import json

person = {
    "name": 'nitin',
    'age': 21,
    'city': 'Meerut',
    'hasChildren': False,
    'titles': ['engineer', 'webDeveloper']
}

# personJson = json.dumps(person, indent=4, sort_keys=True)
# print(personJson)

# with open('person.json', 'w') as file:
#     json.dump(person, file, indent=4)

# with open('person.json', 'r') as file:
#     person = json.load(file)
#     print(person)


class User(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age


user = User('Nitin', 21)


def encode_user(obj):
    if isinstance(obj, User):
        return {
            'name': obj.name,
            'age': obj.age,
            obj.__class__.__name__: True
        }
    else:
        raise TypeError('Object of type User ')


class UserEncoder(JSONEncoder):
    def default(self, obj):
        if isinstance(obj, User):
            return {
                'name': obj.name,
                'age': obj.age,
                obj.__class__.__name__: True
            }
        return JSONEncoder.default(self, obj)


userJson = json.dumps(user, cls=UserEncoder)
usJso = encode_user(user)

print(userJson, usJso)
