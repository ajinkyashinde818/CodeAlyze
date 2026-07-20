from functools import reduce
data = [59, 23, 8]
print(reduce(lambda left, right: left + right, data))
