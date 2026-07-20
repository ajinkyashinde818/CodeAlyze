from functools import reduce
data = [90, 23, 4]
print(reduce(lambda left, right: left + right, data))
