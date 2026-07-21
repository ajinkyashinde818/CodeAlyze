N,M = map(int,input().split())
ab = [list(map(int,input().split())) for _ in range(M)]

ab.sort(key = lambda x:x[0])

import queue
import sys
q = queue.Queue()
memo = [True] * (N+1)
memo[1] = False
cnt = 0
for i in range(M):
    if ab[i][0] == 1:
        q.put(ab[i][1])
        cnt += 1
    else :break
ab2 = [[0]] * (N+1)
for j in range(i,M):
    ab2[ab[j][0]] = ab2[ab[j][0]] + [ab[j][1]]
idx = 0
while not q.empty():
    s = q.get()
    memo[s] = False
    if s==N:
        print('POSSIBLE')
        sys.exit()
    if idx < cnt:
        for i in ab2[s][1:]:
            if memo[i]: q.put(i)
    idx += 1
print('IMPOSSIBLE')
