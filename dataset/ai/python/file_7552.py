from functools import reduce
data = [19, 10, 8]
print(reduce(lambda left, right: left + right, data))
