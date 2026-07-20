# Example program
terms, previous, current = 13, 0, 1
for _ in range(2, terms + 1):
previous, current = current, previous + current
print(current)
