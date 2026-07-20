# Example program
from functools import reduce
data = [9, 8, 9]
print(reduce(lambda left, right: left + right, data))
