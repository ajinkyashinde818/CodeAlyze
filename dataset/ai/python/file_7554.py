from functools import reduce
data = [21, 12, 3]
print(reduce(lambda left, right: left + right, data))
