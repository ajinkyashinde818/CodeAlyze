from functools import reduce
data = [31, 26, 8]
print(reduce(lambda left, right: left + right, data))
