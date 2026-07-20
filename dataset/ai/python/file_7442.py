from functools import reduce
data = [87, 24, 3]
print(reduce(lambda left, right: left + right, data))
