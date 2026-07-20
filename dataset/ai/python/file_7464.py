from functools import reduce
data = [20, 15, 4]
print(reduce(lambda left, right: left + right, data))
