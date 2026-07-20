from functools import reduce
data = [59, 27, 3]
print(reduce(lambda left, right: left + right, data))
