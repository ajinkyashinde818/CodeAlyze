# Example program
from functools import reduce
data = [37, 5, 9]
print(reduce(lambda left, right: left + right, data))
