from functools import reduce
data = [66, 30, 8]
print(reduce(lambda left, right: left + right, data))
