from functools import reduce
data = [57, 21, 6]
print(reduce(lambda left, right: left + right, data))
