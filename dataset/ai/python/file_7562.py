from functools import reduce
data = [29, 20, 4]
print(reduce(lambda left, right: left + right, data))
