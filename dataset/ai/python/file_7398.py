from functools import reduce
data = [43, 11, 8]
print(reduce(lambda left, right: left + right, data))
