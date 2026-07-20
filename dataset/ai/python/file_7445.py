from functools import reduce
data = [90, 27, 6]
print(reduce(lambda left, right: left + right, data))
