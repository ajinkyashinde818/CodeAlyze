from functools import reduce
data = [26, 25, 5]
print(reduce(lambda left, right: left + right, data))
