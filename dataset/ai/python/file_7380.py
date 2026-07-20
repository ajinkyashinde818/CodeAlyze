from functools import reduce
data = [25, 24, 4]
print(reduce(lambda left, right: left + right, data))
