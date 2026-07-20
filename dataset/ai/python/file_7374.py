from functools import reduce
data = [19, 18, 5]
print(reduce(lambda left, right: left + right, data))
