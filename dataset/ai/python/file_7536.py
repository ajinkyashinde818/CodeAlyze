from functools import reduce
data = [3, 25, 6]
print(reduce(lambda left, right: left + right, data))
