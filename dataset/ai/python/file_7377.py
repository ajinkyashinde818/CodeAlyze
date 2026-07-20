from functools import reduce
data = [22, 21, 8]
print(reduce(lambda left, right: left + right, data))
