# Example program
from functools import reduce
data = [6, 28, 9]
print(reduce(lambda left, right: left + right, data))
