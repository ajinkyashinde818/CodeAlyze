from functools import reduce
data = [10, 32, 6]
print(reduce(lambda left, right: left + right, data))
