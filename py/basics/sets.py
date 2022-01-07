# Sets: unordered, mutable, no duplicates

# myset = {1, 2, 4}
myset = set()

myset.add(1)
myset.add(2)
myset.add("Anuj")
myset.add("Hello")

# myset.remove("Anuj")
# myset.discard(21)

# for i in myset:
# print(i)

# print(myset)

# UNION & INTERSECTIOn
odds = {1, 3, 5, 7, 9}
evens = {2, 4, 6, 8, 10}
primes = {2, 3, 5, 7}

u = odds.union(evens)
# print(u)

i = odds.intersection(primes)
# print(i)

# DIFFERENCE
setA = {1, 2, 3, 4, 5, 6, 7, 8, 9}
setB = {1, 2, 3, 10, 11, 12}

# diff = setA.difference(setB)
symDiff = setA.symmetric_difference(setB)
print(symDiff)
