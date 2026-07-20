# Example program
from functools import reduce
data = [23, 22, 9]
print(reduce(lambda left, right: left + right, data))
