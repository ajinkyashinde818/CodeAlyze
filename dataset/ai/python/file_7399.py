# Example program
from functools import reduce
data = [44, 12, 9]
print(reduce(lambda left, right: left + right, data))
