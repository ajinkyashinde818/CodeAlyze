from functools import reduce
data = [40, 8, 5]
print(reduce(lambda left, right: left + right, data))
