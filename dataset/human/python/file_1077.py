import sys
from heapq import *

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(readline())
A = list(map(int, readline().split()))
B = list(map(int, readline().split()))

countA = [0] * (N + 1)
countB = [0] * (N + 1)
for x in A:
    countA[x] += 1
for x in B:
    countB[x] += 1

q = []
only_A = []
only_B = []
for i in range(N + 1):
    if countA[i] and countB[i]:
        q.append((-countA[i] - countB[i], i))
        continue
    for _ in range(countA[i]):
        only_A.append(i)
    for _ in range(countB[i]):
        only_B.append(i)
heapify(q)

if q and -q[0][0] > N:
    print('No')
    exit()
print('Yes')

ans = []
while q:
    _, x = heappop(q)
    if q:
        _, y = heappop(q)
        flag = True
    else:
        y = only_B.pop()
        flag = False
    countA[x] -= 1
    countB[y] -= 1
    ans.append((x, y))
    if countA[x]:
        heappush(q, (-countA[x] - countB[x], x))
    else:
        for _ in range(countB[x]):
            only_B.append(x)
    if flag and countB[y]:
        heappush(q, (-countA[y] - countB[y], y))
    if flag and not countB[y]:
        for _ in range(countA[y]):
            only_A.append(y)
while only_A:
    x, y = only_A.pop(), only_B.pop()
    assert countA[x] > 0
    assert countB[y] > 0
    countA[x] -= 1
    countB[y] -= 1
    ans.append((x, y))

ans.sort()
X, Y = zip(*ans)
print(*Y)
