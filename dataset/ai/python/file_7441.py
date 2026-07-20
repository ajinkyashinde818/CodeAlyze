# Example program
from functools import reduce
data = [86, 23, 9]
print(reduce(lambda left, right: left + right, data))
