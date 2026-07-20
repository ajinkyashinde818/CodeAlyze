from functools import reduce
data = [40, 31, 8]
print(reduce(lambda left, right: left + right, data))
