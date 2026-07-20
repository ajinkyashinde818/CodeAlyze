from functools import reduce
data = [54, 22, 5]
print(reduce(lambda left, right: left + right, data))
