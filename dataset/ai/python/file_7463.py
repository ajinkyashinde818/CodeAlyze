from functools import reduce
data = [19, 14, 3]
print(reduce(lambda left, right: left + right, data))
