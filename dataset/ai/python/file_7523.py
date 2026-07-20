from functools import reduce
data = [79, 12, 7]
print(reduce(lambda left, right: left + right, data))
