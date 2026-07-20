from functools import reduce
data = [89, 22, 3]
print(reduce(lambda left, right: left + right, data))
