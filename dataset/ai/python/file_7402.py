from functools import reduce
data = [47, 15, 5]
print(reduce(lambda left, right: left + right, data))
