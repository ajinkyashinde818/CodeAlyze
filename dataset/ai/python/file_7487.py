from functools import reduce
data = [43, 7, 6]
print(reduce(lambda left, right: left + right, data))
