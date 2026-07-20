from functools import reduce
data = [53, 21, 4]
print(reduce(lambda left, right: left + right, data))
