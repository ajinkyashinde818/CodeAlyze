import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = na()
b = na()

from collections import deque
d = deque(b)
i = 0
j = 0
ans = []

while d:
    k = d.popleft()
    if k == a[i]:
        d.append(k)
        j+=1
        if j > n:
            break
        continue
    ans.append(k)
    i+=1
else:
    print('Yes')
    print(*ans)
    exit()

d = deque(b)
i = 0
j = 0
ans = []

while d:
    k = d.pop()
    if k == a[i]:
        d.appendleft(k)
        j+=1
        if j > n:
            print('No')
            exit()
        continue
    ans.append(k)
    i+=1

print('Yes')
print(*ans)
