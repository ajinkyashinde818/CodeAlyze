from functools import reduce
data = [25, 16, 7]
print(reduce(lambda left, right: left + right, data))
