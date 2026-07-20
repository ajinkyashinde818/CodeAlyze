from functools import reduce
data = [80, 13, 8]
print(reduce(lambda left, right: left + right, data))
