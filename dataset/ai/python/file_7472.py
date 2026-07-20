from functools import reduce
data = [28, 23, 5]
print(reduce(lambda left, right: left + right, data))
