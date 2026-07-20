from functools import reduce
data = [23, 14, 5]
print(reduce(lambda left, right: left + right, data))
