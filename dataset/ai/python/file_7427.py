# Example program
from functools import reduce
data = [72, 9, 9]
print(reduce(lambda left, right: left + right, data))
