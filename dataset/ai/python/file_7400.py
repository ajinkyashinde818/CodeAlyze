from functools import reduce
data = [45, 13, 3]
print(reduce(lambda left, right: left + right, data))
