from functools import reduce
data = [55, 23, 6]
print(reduce(lambda left, right: left + right, data))
