def values(limit):
    for item in range(limit):
yield item
print(list(values(4)))
