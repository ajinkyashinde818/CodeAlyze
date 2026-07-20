from functools import reduce
data = [10, 5, 8]
print(reduce(lambda left, right: left + right, data))
