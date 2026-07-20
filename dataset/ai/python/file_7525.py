# Example program
from functools import reduce
data = [81, 14, 9]
print(reduce(lambda left, right: left + right, data))
