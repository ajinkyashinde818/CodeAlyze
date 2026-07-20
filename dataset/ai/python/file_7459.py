from functools import reduce
data = [15, 10, 6]
print(reduce(lambda left, right: left + right, data))
