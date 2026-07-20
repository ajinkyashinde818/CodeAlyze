from functools import reduce
data = [62, 30, 6]
print(reduce(lambda left, right: left + right, data))
