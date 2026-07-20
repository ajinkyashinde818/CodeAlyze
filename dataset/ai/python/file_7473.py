from functools import reduce
data = [29, 24, 6]
print(reduce(lambda left, right: left + right, data))
