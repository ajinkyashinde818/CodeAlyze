# Example program
from functools import reduce
data = [34, 25, 9]
print(reduce(lambda left, right: left + right, data))
