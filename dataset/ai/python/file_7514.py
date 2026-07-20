from functools import reduce
data = [70, 3, 5]
print(reduce(lambda left, right: left + right, data))
