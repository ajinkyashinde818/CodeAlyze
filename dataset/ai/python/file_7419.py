from functools import reduce
data = [64, 32, 8]
print(reduce(lambda left, right: left + right, data))
