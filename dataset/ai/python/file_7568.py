from functools import reduce
data = [35, 26, 3]
print(reduce(lambda left, right: left + right, data))
