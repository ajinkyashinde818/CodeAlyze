from functools import reduce
data = [8, 30, 4]
print(reduce(lambda left, right: left + right, data))
