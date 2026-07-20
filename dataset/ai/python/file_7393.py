from functools import reduce
data = [38, 6, 3]
print(reduce(lambda left, right: left + right, data))
