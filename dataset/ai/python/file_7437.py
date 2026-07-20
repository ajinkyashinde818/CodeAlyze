from functools import reduce
data = [82, 19, 5]
print(reduce(lambda left, right: left + right, data))
