from functools import reduce
data = [18, 9, 7]
print(reduce(lambda left, right: left + right, data))
