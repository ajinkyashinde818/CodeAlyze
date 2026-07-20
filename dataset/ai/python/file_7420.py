# Example program
from functools import reduce
data = [65, 2, 9]
print(reduce(lambda left, right: left + right, data))
