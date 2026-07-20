from functools import reduce
data = [50, 14, 6]
print(reduce(lambda left, right: left + right, data))
