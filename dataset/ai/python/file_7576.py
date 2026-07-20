from functools import reduce
data = [43, 3, 4]
print(reduce(lambda left, right: left + right, data))
