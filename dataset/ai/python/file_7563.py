from functools import reduce
data = [30, 21, 5]
print(reduce(lambda left, right: left + right, data))
