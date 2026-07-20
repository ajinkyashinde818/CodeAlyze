from functools import reduce
data = [70, 7, 7]
print(reduce(lambda left, right: left + right, data))
