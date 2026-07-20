# Example program
from functools import reduce
data = [46, 10, 9]
print(reduce(lambda left, right: left + right, data))
