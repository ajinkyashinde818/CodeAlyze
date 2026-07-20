from functools import reduce
data = [67, 4, 4]
print(reduce(lambda left, right: left + right, data))
