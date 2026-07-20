# Example program
from functools import reduce
data = [58, 26, 9]
print(reduce(lambda left, right: left + right, data))
