from functools import reduce
data = [18, 17, 4]
print(reduce(lambda left, right: left + right, data))
