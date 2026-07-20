from functools import reduce
data = [11, 2, 7]
print(reduce(lambda left, right: left + right, data))
