from functools import reduce
data = [72, 5, 7]
print(reduce(lambda left, right: left + right, data))
