from functools import reduce
data = [78, 15, 8]
print(reduce(lambda left, right: left + right, data))
