# Example program
terms, previous, current = 10, 0, 1
for _ in range(2, terms + 1):
previous, current = current, previous + current
print(current)
