# Itertools: product, permutation, combinatation, accumukate, groupby, and infinite iterators

# PRODUCT
from itertools import groupby, product

a = [1, 2]
b = [3]

prod = product(a, b, repeat=2)

# PERMUTATIONS
from itertools import permutations

a = [1, 2, 3]
perm = permutations(a, 2)

# COMBINATIONS
from itertools import combinations, combinations_with_replacement

a = [1, 2, 3, 4]
comp = combinations(a, 2)
comb = combinations_with_replacement(a, 2)

# ACCUMULATE

from itertools import accumulate
import operator

a = [1, 2, 5, 3, 4]
acc = accumulate(a, func=max)


# GROUPBY
def smallerThan3(x):
    return x < 3


a = [1, 2, 2, 3, 4]
group = groupby(a, key=lambda x: x < 3)

# for key, value in group:
#     print(key, list(value))

persons = [
    {
        'name': 'Nitin',
        'age': 22
    },
    {
        'name': 'Anuj',
        'age': 26
    },
    {
        'name': 'Geeta',
        'age': 47
    },
    {
        'name': 'Papu',
        'age': 50
    },
]

group_by = groupby(persons, key=lambda x: x['age'])

# for key, value in group_by:
#     print(key, list(value))

from itertools import count, cycle, repeat
