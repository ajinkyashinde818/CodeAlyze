from functools import reduce
data = [61, 29, 5]
print(reduce(lambda left, right: left + right, data))
