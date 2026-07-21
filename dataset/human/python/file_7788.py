import sys


inint = lambda: int(sys.stdin.readline())
inintm = lambda: map(int, sys.stdin.readline().split())
inintl = lambda: list(inintm())
instrm = lambda: map(str, sys.stdin.readline().split())
instrl = lambda: list(instrm())

n, k, s = inintm()

ans = [str(s)]*k

if s != 10**9:
    for i in range(n-k):
        ans.append(str(s+1))
else:
    for i in range(n-k):
        ans.append(str(s-1))

print(" ".join(ans))
