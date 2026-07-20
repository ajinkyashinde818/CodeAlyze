from functools import reduce
data = [52, 20, 3]
print(reduce(lambda left, right: left + right, data))
