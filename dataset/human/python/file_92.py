import sys


inint = lambda: int(sys.stdin.readline())
inintm = lambda: map(int, sys.stdin.readline().split())
inintl = lambda: list(inintm())
instrm = lambda: map(str, sys.stdin.readline().split())
instrl = lambda: list(instrm())

r, g, b, n = inintm()

ans = 0

for i in range(3001):
    for j in range(3001):
        if (n - (i*r + j*g)) >= 0 and (n - (i*r + j*g)) % b == 0:
            ans += 1

print(ans)
