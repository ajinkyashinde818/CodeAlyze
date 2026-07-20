from functools import reduce
data = [22, 13, 4]
print(reduce(lambda left, right: left + right, data))
