import sys
input = lambda: sys.stdin.readline().rstrip()

N, K = map(int, input().split())

A = list(map(int, input().split()))


visited = set()
visited.add(1)
lst = [1, ]

now = 1
flg = 0
for i in range(K):
    now = A[now-1]
    if now in visited:
        last = K - i
        loop_point = now
        flg = 1
        break
    visited.add(now)
    lst.append(now)
if not flg:
    print(lst[-1])
    exit()    

for i in range(len(lst)):
    if lst[i] == loop_point:
        inter = i
        loop = lst[i:]

last = (last-1) % len(loop)
print(loop[last])
