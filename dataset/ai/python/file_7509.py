from functools import reduce
data = [65, 29, 7]
print(reduce(lambda left, right: left + right, data))
