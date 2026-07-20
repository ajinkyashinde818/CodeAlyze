from functools import reduce
data = [48, 16, 6]
print(reduce(lambda left, right: left + right, data))
