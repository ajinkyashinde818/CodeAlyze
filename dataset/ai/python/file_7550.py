from functools import reduce
data = [17, 8, 6]
print(reduce(lambda left, right: left + right, data))
