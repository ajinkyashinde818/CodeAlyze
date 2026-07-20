from functools import reduce
data = [44, 8, 7]
print(reduce(lambda left, right: left + right, data))
