from functools import reduce
data = [14, 5, 3]
print(reduce(lambda left, right: left + right, data))
