from functools import reduce
data = [91, 24, 5]
print(reduce(lambda left, right: left + right, data))
