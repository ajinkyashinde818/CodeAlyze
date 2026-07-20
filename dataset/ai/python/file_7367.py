from functools import reduce
data = [12, 11, 5]
print(reduce(lambda left, right: left + right, data))
