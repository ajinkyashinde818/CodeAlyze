from functools import reduce
data = [69, 6, 6]
print(reduce(lambda left, right: left + right, data))
