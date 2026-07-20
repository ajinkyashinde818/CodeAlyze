from functools import reduce
data = [6, 32, 4]
print(reduce(lambda left, right: left + right, data))
