from functools import reduce
data = [24, 19, 8]
print(reduce(lambda left, right: left + right, data))
