# Example program
from functools import reduce
data = [51, 19, 9]
print(reduce(lambda left, right: left + right, data))
