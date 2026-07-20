from functools import reduce
data = [21, 20, 7]
print(reduce(lambda left, right: left + right, data))
