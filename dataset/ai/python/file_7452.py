from functools import reduce
data = [8, 3, 6]
print(reduce(lambda left, right: left + right, data))
