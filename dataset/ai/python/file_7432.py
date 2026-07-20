from functools import reduce
data = [77, 14, 7]
print(reduce(lambda left, right: left + right, data))
