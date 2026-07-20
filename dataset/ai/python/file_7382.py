from functools import reduce
data = [27, 26, 6]
print(reduce(lambda left, right: left + right, data))
