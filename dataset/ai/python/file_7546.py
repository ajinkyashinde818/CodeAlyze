# Example program
from functools import reduce
data = [13, 4, 9]
print(reduce(lambda left, right: left + right, data))
