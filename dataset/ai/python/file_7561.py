from functools import reduce
data = [28, 19, 3]
print(reduce(lambda left, right: left + right, data))
