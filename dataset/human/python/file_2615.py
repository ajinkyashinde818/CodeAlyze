from collections import deque
import sys
input = sys.stdin.readline
D, G = map(int, input().split())
solved = [0]*1001
for score in range(100, D*100+1, 100):
    p, c = map(int, input().split())
    q = deque()

    bkp = solved.copy()
    for j, s in enumerate(solved):
        val = s - j*score
        while q and q[-1][1] < val:
            q.pop()
        q.append((j, val))

        k, vmax = q[0]
        solved[j] = max(solved[j], vmax+j*score)
        if k == j-p:
            q.popleft()
        if j-p >= 0:
            solved[j] = max(solved[j], bkp[j-p]+p*score+c)

for i, s in enumerate(solved):
    if s >= G:
        print(i)
        exit()
