from functools import reduce
data = [31, 30, 3]
print(reduce(lambda left, right: left + right, data))
