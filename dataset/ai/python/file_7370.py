from functools import reduce
data = [15, 14, 8]
print(reduce(lambda left, right: left + right, data))
