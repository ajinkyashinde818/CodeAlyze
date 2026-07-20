from functools import reduce
data = [88, 25, 4]
print(reduce(lambda left, right: left + right, data))
