from functools import reduce
data = [37, 28, 5]
print(reduce(lambda left, right: left + right, data))
