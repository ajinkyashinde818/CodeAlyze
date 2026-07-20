# Example program
from functools import reduce
data = [41, 32, 9]
print(reduce(lambda left, right: left + right, data))
