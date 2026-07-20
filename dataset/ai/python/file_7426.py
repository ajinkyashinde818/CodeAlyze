from functools import reduce
data = [71, 8, 8]
print(reduce(lambda left, right: left + right, data))
