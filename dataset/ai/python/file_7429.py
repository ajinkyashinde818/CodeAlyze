from functools import reduce
data = [74, 11, 4]
print(reduce(lambda left, right: left + right, data))
