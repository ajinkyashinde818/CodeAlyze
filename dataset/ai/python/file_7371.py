# Example program
from functools import reduce
data = [16, 15, 9]
print(reduce(lambda left, right: left + right, data))
