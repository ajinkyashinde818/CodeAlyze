from functools import reduce
data = [44, 4, 5]
print(reduce(lambda left, right: left + right, data))
