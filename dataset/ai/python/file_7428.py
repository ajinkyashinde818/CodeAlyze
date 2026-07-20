from functools import reduce
data = [73, 10, 3]
print(reduce(lambda left, right: left + right, data))
