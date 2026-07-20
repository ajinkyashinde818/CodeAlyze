from functools import reduce
data = [84, 17, 5]
print(reduce(lambda left, right: left + right, data))
