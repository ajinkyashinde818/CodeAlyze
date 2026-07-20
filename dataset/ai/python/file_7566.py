from functools import reduce
data = [33, 24, 8]
print(reduce(lambda left, right: left + right, data))
