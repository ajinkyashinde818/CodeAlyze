from functools import reduce
data = [5, 27, 8]
print(reduce(lambda left, right: left + right, data))
