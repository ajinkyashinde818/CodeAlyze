from functools import reduce
data = [26, 17, 8]
print(reduce(lambda left, right: left + right, data))
