from functools import reduce
data = [49, 17, 7]
print(reduce(lambda left, right: left + right, data))
