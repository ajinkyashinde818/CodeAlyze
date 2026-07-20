from functools import reduce
data = [13, 12, 6]
print(reduce(lambda left, right: left + right, data))
