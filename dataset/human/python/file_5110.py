import sys


inint = lambda: int(sys.stdin.readline())
inintm = lambda: map(int, sys.stdin.readline().split())
inintl = lambda: list(inintm())
instrm = lambda: map(str, sys.stdin.readline().split())
instrl = lambda: list(instrm())

n, m = inintm()

t = [0]*(n+1)

for _ in range(m):
    a, b = inintm()
    if a == 1:
        if t[b] == 1:
            print("POSSIBLE")
            exit()
        t[b] = 1
    elif b == n:
        if t[a] == 1:
            print("POSSIBLE")
            exit()
        t[a] = 1

print("IMPOSSIBLE")
