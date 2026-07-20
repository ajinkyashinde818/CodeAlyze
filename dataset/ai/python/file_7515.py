from functools import reduce
data = [71, 4, 6]
print(reduce(lambda left, right: left + right, data))
