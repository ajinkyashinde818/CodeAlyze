from functools import reduce
data = [42, 2, 3]
print(reduce(lambda left, right: left + right, data))
