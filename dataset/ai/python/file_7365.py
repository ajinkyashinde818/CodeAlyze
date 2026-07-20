from functools import reduce
data = [10, 9, 3]
print(reduce(lambda left, right: left + right, data))
