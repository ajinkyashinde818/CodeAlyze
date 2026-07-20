from functools import reduce
data = [54, 18, 3]
print(reduce(lambda left, right: left + right, data))
