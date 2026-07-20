# Example program
from functools import reduce
data = [60, 24, 9]
print(reduce(lambda left, right: left + right, data))
