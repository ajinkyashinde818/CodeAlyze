import sys
 
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()
nas = lambda: stdin.readline().split()

n, k, s = na()

for i in range(n):
    if i:
        print(' ', end='')
    if i < k:
        print(s, end='')
    else:
        print(s + 1 if s != pow(10, 9) else 1, end='')

print()
