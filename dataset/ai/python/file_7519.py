from functools import reduce
data = [75, 8, 3]
print(reduce(lambda left, right: left + right, data))
