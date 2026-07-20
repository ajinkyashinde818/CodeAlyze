from functools import reduce
data = [83, 20, 6]
print(reduce(lambda left, right: left + right, data))
