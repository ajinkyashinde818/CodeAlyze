from collections import deque
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
cntA = [0] * (N + 1)
cntB = [0] * (N + 1)
for i in range(N):
    cntA[A[i]] += 1
    cntB[B[i]] += 1
nums = [(cntA[i], cntB[i], i) for i in range(1, N+1) if cntA[i] or cntB[i]]
nums.sort(key=lambda p: p[0] + p[1], reverse=True)
a = deque()
b = deque()
c = deque(list(range(N)))
ansa = [0] * N
ansb = [0] * N
for x, y, n in nums:
    if x + y > len(a) + len(b) + len(c):
        print('No')
        exit()
    ra = x - len(a)
    rb = y - len(b)
    for i in range(ra):
        ansa[c[0]] = n
        b.append(c[0])
        c.popleft()
        x -= 1
    for i in range(rb):
        ansb[c[0]] = n
        a.append(c[0])
        c.popleft()
        y -= 1
    while c and (x or y):
        if x:
            ansa[c[0]] = n
            b.append(c[0])
            x -= 1
        else:
            ansb[c[0]] = n
            a.append(c[0])
            y -= 1
        c.popleft()
    for i in range(x):
        ansa[a[0]] = n
        a.popleft()
    for i in range(y):
        ansb[b[0]] = n
        b.popleft()
ans = [(ansa[i], ansb[i]) for i in range(N)]
ans.sort()
print('Yes')
print(*[p[1] for p in ans])
