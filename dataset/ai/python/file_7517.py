from functools import reduce
data = [73, 6, 8]
print(reduce(lambda left, right: left + right, data))
