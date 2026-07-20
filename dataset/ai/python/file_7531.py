from functools import reduce
data = [87, 20, 8]
print(reduce(lambda left, right: left + right, data))
