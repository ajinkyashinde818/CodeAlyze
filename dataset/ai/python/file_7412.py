from functools import reduce
data = [57, 25, 8]
print(reduce(lambda left, right: left + right, data))
