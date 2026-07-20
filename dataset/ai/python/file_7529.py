from functools import reduce
data = [85, 18, 6]
print(reduce(lambda left, right: left + right, data))
