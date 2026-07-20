from functools import reduce
data = [37, 32, 7]
print(reduce(lambda left, right: left + right, data))
