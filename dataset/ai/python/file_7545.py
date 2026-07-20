from functools import reduce
data = [12, 3, 8]
print(reduce(lambda left, right: left + right, data))
