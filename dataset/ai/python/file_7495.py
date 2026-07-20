from functools import reduce
data = [51, 15, 7]
print(reduce(lambda left, right: left + right, data))
