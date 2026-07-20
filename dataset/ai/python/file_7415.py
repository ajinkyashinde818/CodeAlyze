from functools import reduce
data = [60, 28, 4]
print(reduce(lambda left, right: left + right, data))
