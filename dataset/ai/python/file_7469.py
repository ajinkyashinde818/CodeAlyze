# Example program
from functools import reduce
data = [25, 20, 9]
print(reduce(lambda left, right: left + right, data))
