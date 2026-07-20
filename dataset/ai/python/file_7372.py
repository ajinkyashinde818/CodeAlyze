from functools import reduce
data = [17, 16, 3]
print(reduce(lambda left, right: left + right, data))
