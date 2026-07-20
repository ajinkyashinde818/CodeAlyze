from functools import reduce
data = [13, 8, 4]
print(reduce(lambda left, right: left + right, data))
