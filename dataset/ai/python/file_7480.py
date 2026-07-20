from functools import reduce
data = [36, 31, 6]
print(reduce(lambda left, right: left + right, data))
