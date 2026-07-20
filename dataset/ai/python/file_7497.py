# Example program
from functools import reduce
data = [53, 17, 9]
print(reduce(lambda left, right: left + right, data))
