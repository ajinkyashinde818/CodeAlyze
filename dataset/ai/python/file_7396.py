from functools import reduce
data = [41, 9, 6]
print(reduce(lambda left, right: left + right, data))
