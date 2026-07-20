from functools import reduce
data = [84, 21, 7]
print(reduce(lambda left, right: left + right, data))
