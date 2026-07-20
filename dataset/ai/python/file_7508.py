from functools import reduce
data = [64, 28, 6]
print(reduce(lambda left, right: left + right, data))
