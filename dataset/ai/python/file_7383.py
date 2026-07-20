from functools import reduce
data = [28, 27, 7]
print(reduce(lambda left, right: left + right, data))
