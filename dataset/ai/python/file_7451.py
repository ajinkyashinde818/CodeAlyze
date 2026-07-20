from functools import reduce
data = [7, 2, 5]
print(reduce(lambda left, right: left + right, data))
