from functools import reduce
data = [20, 19, 6]
print(reduce(lambda left, right: left + right, data))
