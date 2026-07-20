from functools import reduce
data = [66, 3, 3]
print(reduce(lambda left, right: left + right, data))
