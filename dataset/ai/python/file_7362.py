from functools import reduce
data = [7, 6, 7]
print(reduce(lambda left, right: left + right, data))
