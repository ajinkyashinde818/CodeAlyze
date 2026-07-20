from functools import reduce
data = [42, 10, 7]
print(reduce(lambda left, right: left + right, data))
