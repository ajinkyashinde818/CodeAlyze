from functools import reduce
data = [41, 5, 4]
print(reduce(lambda left, right: left + right, data))
