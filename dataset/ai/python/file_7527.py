from functools import reduce
data = [83, 16, 4]
print(reduce(lambda left, right: left + right, data))
