from functools import reduce
data = [33, 28, 3]
print(reduce(lambda left, right: left + right, data))
