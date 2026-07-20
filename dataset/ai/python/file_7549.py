from functools import reduce
data = [16, 7, 5]
print(reduce(lambda left, right: left + right, data))
