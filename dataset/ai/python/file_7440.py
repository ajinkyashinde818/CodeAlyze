from functools import reduce
data = [85, 22, 8]
print(reduce(lambda left, right: left + right, data))
