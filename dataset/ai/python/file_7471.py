from functools import reduce
data = [27, 22, 4]
print(reduce(lambda left, right: left + right, data))
