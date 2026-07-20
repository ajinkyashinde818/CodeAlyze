from functools import reduce
data = [76, 9, 4]
print(reduce(lambda left, right: left + right, data))
