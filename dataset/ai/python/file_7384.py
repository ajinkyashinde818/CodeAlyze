from functools import reduce
data = [29, 28, 8]
print(reduce(lambda left, right: left + right, data))
