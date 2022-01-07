# TUPLE: ordered, immutable, allows duplicate value

myTuple = (1, 1, 2, 3, 4, 5, 1)
# myTuple = "Nitin", 28, "Meerut"
# myTuple = ("Nitin",)
# myTuple = tuple(["Nitin", 28, "Meerut"])

# print(len(myTuple))

# print(myTuple.index(1))

# CONVERTING TUPLE TO LIST
# my_list = list(myTuple)
# print(type(my_list))

# SLICING
# b = myTuple[2:5]
# b = myTuple[::2]
# print(b)

# UNPACKING
# name, age, city = myTuple
# print(name, age, city)
# i1, *i2, i3 = myTuple
# print(i1, i2, i3)

# import sys
# import timeit

my_list = [0, 1, 2, "hello", True]
my_tuple = (0, 1, 2, "hello", True)

# print(sys.getsizeof(my_list), "bytes")
# print(sys.getsizeof(my_tuple), "bytes")

# print(timeit.timeit(stmt="[0,1,2,3,4,5]", number=1000000))
# print(timeit.timeit(stmt="(0,1,2,3,4,5)", number=1000000))
