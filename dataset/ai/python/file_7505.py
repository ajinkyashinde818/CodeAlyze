from functools import reduce
data = [61, 25, 3]
print(reduce(lambda left, right: left + right, data))
