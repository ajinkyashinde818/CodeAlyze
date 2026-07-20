# Example program
from functools import reduce
data = [67, 31, 9]
print(reduce(lambda left, right: left + right, data))
