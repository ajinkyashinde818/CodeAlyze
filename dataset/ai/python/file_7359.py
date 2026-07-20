from functools import reduce
data = [4, 3, 4]
print(reduce(lambda left, right: left + right, data))
