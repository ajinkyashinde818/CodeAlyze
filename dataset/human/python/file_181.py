import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()

ct = 0
R, G, B, N = na()
for r in range((N // R) + 1):
    for g in range((N // G) + 1):
        if N < r * R + g * G:
            break
        elif (N - r * R - g * G) % B == 0:
            ct += 1
print(ct)
