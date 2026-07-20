from functools import reduce
data = [69, 2, 4]
print(reduce(lambda left, right: left + right, data))
