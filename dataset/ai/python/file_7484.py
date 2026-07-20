from functools import reduce
data = [40, 4, 3]
print(reduce(lambda left, right: left + right, data))
