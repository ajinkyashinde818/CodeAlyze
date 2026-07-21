from collections import deque

s = input()
n = len(s)
l = deque([])
r = deque([])
c = 0

for i in range(n):
    if s[i] != "x": l.append(s[i])
    if s[n-1-i] != "x": r.append(s[n-1-i])

if l != r:
    print(-1)
    exit(0)

if len(l) % 2 == 1: c = len(l) // 2 + 1
else: c = len(l) // 2

cntl = [0]*c
cntr = [0]*c

k = 0
i = 0

while k < c:
    if s[i] == "x":
        cntl[k] += 1
    else:
        k += 1
    i += 1

k = 0
i = n-1

while k < c:
    if s[i] == "x":
        cntr[k] += 1
    else:
        k += 1
    i -= 1

ans = 0

for j in range(c):
    ans += abs(cntl[j] - cntr[j])

print(ans)
