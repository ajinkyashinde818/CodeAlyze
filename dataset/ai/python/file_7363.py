from functools import reduce
data = [8, 7, 8]
print(reduce(lambda left, right: left + right, data))
