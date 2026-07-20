from functools import reduce
data = [30, 25, 7]
print(reduce(lambda left, right: left + right, data))
