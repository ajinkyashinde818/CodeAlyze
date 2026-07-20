from functools import reduce
data = [76, 13, 6]
print(reduce(lambda left, right: left + right, data))
