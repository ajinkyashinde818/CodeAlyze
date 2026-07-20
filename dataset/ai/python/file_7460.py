from functools import reduce
data = [16, 11, 7]
print(reduce(lambda left, right: left + right, data))
