from functools import reduce
data = [33, 32, 5]
print(reduce(lambda left, right: left + right, data))
