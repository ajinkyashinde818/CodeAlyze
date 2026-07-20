from functools import reduce
data = [68, 32, 3]
print(reduce(lambda left, right: left + right, data))
