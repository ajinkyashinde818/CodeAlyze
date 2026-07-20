from functools import reduce
data = [58, 22, 7]
print(reduce(lambda left, right: left + right, data))
