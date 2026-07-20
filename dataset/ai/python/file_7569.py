from functools import reduce
data = [36, 27, 4]
print(reduce(lambda left, right: left + right, data))
