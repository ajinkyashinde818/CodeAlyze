from functools import reduce
data = [35, 3, 7]
print(reduce(lambda left, right: left + right, data))
