from functools import reduce
data = [52, 16, 8]
print(reduce(lambda left, right: left + right, data))
