# Collections: Counter, namedtuple, OrderedDict, defaultDict, deque

# 1. Counter
from collections import Counter

a = "aaaaabcaabbbbcc"
my_counter = Counter(a)
# print(my_counter.items())
# print(my_counter.most_common(1))

#NamedTuple
from collections import namedtuple

Point = namedtuple('Point', 'x, y')
pt = Point(1, -4)
# print(pt.x)

# OrderedDict
from collections import OrderedDict

ordered = OrderedDict()

ordered['a'] = 1
ordered['b'] = 2
ordered['c'] = 3
ordered['d'] = 4

# print(ordered)

from collections import defaultdict

d = defaultdict(int)
d['a'] = 1
d['b'] = 2
d['c'] = 3
d['d'] = 4

# print(d)

# DEQUE
from collections import deque

q = deque()
q.append('nitin')
q.appendleft('panwar')

# print(q)
