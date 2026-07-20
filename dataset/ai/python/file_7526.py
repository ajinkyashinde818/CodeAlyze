from functools import reduce
data = [82, 15, 3]
print(reduce(lambda left, right: left + right, data))
