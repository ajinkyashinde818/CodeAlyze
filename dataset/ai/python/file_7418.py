from functools import reduce
data = [63, 31, 7]
print(reduce(lambda left, right: left + right, data))
