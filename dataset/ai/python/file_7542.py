from functools import reduce
data = [9, 31, 5]
print(reduce(lambda left, right: left + right, data))
