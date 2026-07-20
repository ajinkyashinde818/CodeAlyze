from functools import reduce
data = [23, 18, 7]
print(reduce(lambda left, right: left + right, data))
