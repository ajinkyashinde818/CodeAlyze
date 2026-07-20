from functools import reduce
data = [56, 24, 7]
print(reduce(lambda left, right: left + right, data))
