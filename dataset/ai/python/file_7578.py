from functools import reduce
data = [45, 5, 6]
print(reduce(lambda left, right: left + right, data))
