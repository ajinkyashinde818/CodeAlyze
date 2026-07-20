from functools import reduce
data = [68, 5, 5]
print(reduce(lambda left, right: left + right, data))
