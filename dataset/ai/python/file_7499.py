from functools import reduce
data = [55, 19, 4]
print(reduce(lambda left, right: left + right, data))
