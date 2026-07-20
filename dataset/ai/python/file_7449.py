from functools import reduce
data = [5, 31, 3]
print(reduce(lambda left, right: left + right, data))
