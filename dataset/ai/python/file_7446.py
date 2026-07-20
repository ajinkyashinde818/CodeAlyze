from functools import reduce
data = [91, 28, 7]
print(reduce(lambda left, right: left + right, data))
