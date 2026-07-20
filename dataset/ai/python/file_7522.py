from functools import reduce
data = [78, 11, 6]
print(reduce(lambda left, right: left + right, data))
