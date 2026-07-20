from functools import reduce
data = [21, 16, 5]
print(reduce(lambda left, right: left + right, data))
