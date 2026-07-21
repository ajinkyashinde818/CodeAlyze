import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

s = ns()
s = list(s)
flag = 1
while len(s) != 0:
    if s[-5:] == list("dream") or s[-5:] == list("erase"):
        del s[-5:]
        continue
    elif s[-6:] == list("eraser"):
        del s[-6:]
        continue
    elif s[-7:] == list("dreamer"):
        del s[-7:]
        continue
    else:
        flag = 0
        break

if flag:
    print("YES")
else:
    print("NO")
