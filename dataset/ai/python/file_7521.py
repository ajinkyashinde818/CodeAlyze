from functools import reduce
data = [77, 10, 5]
print(reduce(lambda left, right: left + right, data))
