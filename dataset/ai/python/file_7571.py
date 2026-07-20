from functools import reduce
data = [38, 29, 6]
print(reduce(lambda left, right: left + right, data))
