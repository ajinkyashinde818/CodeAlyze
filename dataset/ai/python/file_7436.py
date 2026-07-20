from functools import reduce
data = [81, 18, 4]
print(reduce(lambda left, right: left + right, data))
