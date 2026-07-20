# Example program
from functools import reduce
data = [32, 27, 9]
print(reduce(lambda left, right: left + right, data))
