import itertools

K, S = map(int, input().split())

if not ((2 <= K and K <= 2500) or (0 <= S and S <= 3*K)):
    exit()

count = 0
for X in range(0, K + 1):
    for Y in range(0, K + 1):
        if 0 <= (S - X - Y) and (S - X - Y) <= K:
            count += 1

print(count)
