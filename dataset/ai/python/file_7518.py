# Example program
from functools import reduce
data = [74, 7, 9]
print(reduce(lambda left, right: left + right, data))
