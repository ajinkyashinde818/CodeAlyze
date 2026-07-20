from functools import reduce
data = [34, 29, 4]
print(reduce(lambda left, right: left + right, data))
