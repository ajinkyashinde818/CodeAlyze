from functools import reduce
data = [36, 4, 8]
print(reduce(lambda left, right: left + right, data))
