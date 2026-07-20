from functools import reduce
data = [5, 4, 5]
print(reduce(lambda left, right: left + right, data))
