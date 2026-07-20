from functools import reduce
data = [34, 2, 6]
print(reduce(lambda left, right: left + right, data))
