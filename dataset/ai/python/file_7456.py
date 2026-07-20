from functools import reduce
data = [12, 7, 3]
print(reduce(lambda left, right: left + right, data))
