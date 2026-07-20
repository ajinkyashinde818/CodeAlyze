from functools import reduce
data = [89, 26, 5]
print(reduce(lambda left, right: left + right, data))
