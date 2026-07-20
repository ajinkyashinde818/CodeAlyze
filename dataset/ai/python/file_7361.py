from functools import reduce
data = [6, 5, 6]
print(reduce(lambda left, right: left + right, data))
