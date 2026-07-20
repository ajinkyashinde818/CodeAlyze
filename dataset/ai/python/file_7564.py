from functools import reduce
data = [31, 22, 6]
print(reduce(lambda left, right: left + right, data))
