from functools import reduce
data = [80, 17, 3]
print(reduce(lambda left, right: left + right, data))
