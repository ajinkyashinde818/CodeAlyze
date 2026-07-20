from functools import reduce
data = [32, 23, 7]
print(reduce(lambda left, right: left + right, data))
