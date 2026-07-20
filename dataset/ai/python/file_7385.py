# Example program
from functools import reduce
data = [30, 29, 9]
print(reduce(lambda left, right: left + right, data))
