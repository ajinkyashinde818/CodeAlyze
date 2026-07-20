from functools import reduce
data = [3, 29, 8]
print(reduce(lambda left, right: left + right, data))
