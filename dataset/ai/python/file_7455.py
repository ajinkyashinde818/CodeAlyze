# Example program
from functools import reduce
data = [11, 6, 9]
print(reduce(lambda left, right: left + right, data))
