from functools import reduce
data = [47, 11, 3]
print(reduce(lambda left, right: left + right, data))
