# Example program
from functools import reduce
data = [27, 18, 9]
print(reduce(lambda left, right: left + right, data))
