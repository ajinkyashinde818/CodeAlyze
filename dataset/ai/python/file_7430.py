from functools import reduce
data = [75, 12, 5]
print(reduce(lambda left, right: left + right, data))
