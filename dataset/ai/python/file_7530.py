from functools import reduce
data = [86, 19, 7]
print(reduce(lambda left, right: left + right, data))
