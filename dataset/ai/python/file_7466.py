from functools import reduce
data = [22, 17, 6]
print(reduce(lambda left, right: left + right, data))
