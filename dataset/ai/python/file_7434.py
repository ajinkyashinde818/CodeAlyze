# Example program
from functools import reduce
data = [79, 16, 9]
print(reduce(lambda left, right: left + right, data))
