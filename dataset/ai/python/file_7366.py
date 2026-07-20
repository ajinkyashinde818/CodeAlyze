from functools import reduce
data = [11, 10, 4]
print(reduce(lambda left, right: left + right, data))
