from functools import reduce
data = [35, 30, 5]
print(reduce(lambda left, right: left + right, data))
