from functools import reduce
data = [15, 6, 4]
print(reduce(lambda left, right: left + right, data))
