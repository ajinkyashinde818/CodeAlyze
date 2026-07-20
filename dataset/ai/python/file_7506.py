from functools import reduce
data = [62, 26, 4]
print(reduce(lambda left, right: left + right, data))
