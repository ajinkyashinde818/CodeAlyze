from functools import reduce
data = [56, 20, 5]
print(reduce(lambda left, right: left + right, data))
