from functools import reduce
data = [63, 27, 5]
print(reduce(lambda left, right: left + right, data))
