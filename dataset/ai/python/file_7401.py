from functools import reduce
data = [46, 14, 4]
print(reduce(lambda left, right: left + right, data))
