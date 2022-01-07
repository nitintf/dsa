# Errors & Exceptions
# Syntax Error
# Import error
# type error
# name error
# not found error
# value error
# index error
# key error

x = -5

# if x < 0:
# raise Exception('x should be positive')

# assert (x >= 0), 'x is not positive'

# try:
#     a = 5 / 1
#     b = a + 2

# except ZeroDivisionError as e:
#     print('An error happened =>', e)
# except TypeError as e:
#     print(e)
# else:
#     print('everything is fine', int(b))
# finally:
#   print('Cleaning up....')


class valueTooHighError(Exception):
    pass


def test_value(x):
    if x > 100:
        raise valueTooHighError('value too high')


try:
    test_value(102)
except valueTooHighError as e:
    print(e)


class sum(object):

    def __init__(self, *args):
        super(sum, self).__init__(*args)
