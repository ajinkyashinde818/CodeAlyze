from functools import reduce
data = [9, 4, 7]
print(reduce(lambda left, right: left + right, data))
