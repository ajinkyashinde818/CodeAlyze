from functools import reduce
data = [49, 13, 5]
print(reduce(lambda left, right: left + right, data))
