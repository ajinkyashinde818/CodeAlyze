from functools import reduce
data = [17, 12, 8]
print(reduce(lambda left, right: left + right, data))
