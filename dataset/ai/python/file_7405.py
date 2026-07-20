from functools import reduce
data = [50, 18, 8]
print(reduce(lambda left, right: left + right, data))
