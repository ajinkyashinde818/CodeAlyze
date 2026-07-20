from functools import reduce
data = [39, 7, 4]
print(reduce(lambda left, right: left + right, data))
