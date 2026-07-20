from functools import reduce
data = [45, 9, 8]
print(reduce(lambda left, right: left + right, data))
