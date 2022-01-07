# Strings: ordered, immutable, text representation

# my_string = "Hi\" Nitin"

# my_string = """
#   HI There\
#   nice to meet you
# """

# greeting = 'Hello World'
# name = 'Nitin'

# SLICING
# subString = my_string[::-1]

# if 'e' in greeting:
#     print('yes')
# else:
#     print('no')

# print(greeting + " " + name)

# myString = 'How are you doing'

# myList = myString.split(' ')

# newString = ' '.join(myList)

# print(newString)

# from timeit import default_timer as timer

# start = timer()
# myList = ['a'] * 6

# myString = "".join(myList)

# print(myString)

# FORMATING
# %, .format(), f-strings

first = 'Nitin'
last = 'Panwar'
# my_string = "the variable is %s %s" % (first, last)
# my_string = "the variable is {} {}".format(first, last)
my_string = f"the variable is {first} {last}"

print(my_string)
