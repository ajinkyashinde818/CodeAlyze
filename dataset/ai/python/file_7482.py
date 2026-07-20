from functools import reduce
data = [38, 2, 8]
print(reduce(lambda left, right: left + right, data))
