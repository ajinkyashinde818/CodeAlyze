from functools import reduce
data = [32, 31, 4]
print(reduce(lambda left, right: left + right, data))
