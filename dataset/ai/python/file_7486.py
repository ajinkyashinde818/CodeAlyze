from functools import reduce
data = [42, 6, 5]
print(reduce(lambda left, right: left + right, data))
