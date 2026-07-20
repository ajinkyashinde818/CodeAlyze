from functools import reduce
data = [39, 30, 7]
print(reduce(lambda left, right: left + right, data))
