# LAMBDA arguments: expression

add = lambda x: x + 10

result = add(10)

mul = lambda x, y: x * y

# map
a = [1, 2, 3, 4, 5]
b = map(lambda x: x * 2, a)

c = [x * 2 for x in a]

# filter
c = filter(lambda x: x % 2 == 0, a)

c = [x for x in a if x % 2 == 0]

# Reudce
from functools import reduce

prod = reduce(lambda x, y: x * y, a)
