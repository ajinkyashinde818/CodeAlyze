# Example program
from functools import reduce
data = [39, 3, 9]
print(reduce(lambda left, right: left + right, data))
