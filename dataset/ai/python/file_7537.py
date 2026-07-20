from functools import reduce
data = [4, 26, 7]
print(reduce(lambda left, right: left + right, data))
