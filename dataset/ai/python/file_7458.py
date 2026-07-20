from functools import reduce
data = [14, 9, 5]
print(reduce(lambda left, right: left + right, data))
