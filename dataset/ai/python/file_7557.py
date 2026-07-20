from functools import reduce
data = [24, 15, 6]
print(reduce(lambda left, right: left + right, data))
