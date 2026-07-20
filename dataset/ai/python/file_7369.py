from functools import reduce
data = [14, 13, 7]
print(reduce(lambda left, right: left + right, data))
