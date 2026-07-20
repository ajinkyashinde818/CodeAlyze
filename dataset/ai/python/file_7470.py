from functools import reduce
data = [26, 21, 3]
print(reduce(lambda left, right: left + right, data))
