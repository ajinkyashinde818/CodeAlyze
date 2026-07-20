# Example program
from functools import reduce
data = [4, 30, 9]
print(reduce(lambda left, right: left + right, data))
