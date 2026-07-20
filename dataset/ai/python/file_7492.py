from functools import reduce
data = [48, 12, 4]
print(reduce(lambda left, right: left + right, data))
