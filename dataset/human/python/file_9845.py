import sys
from collections import deque, defaultdict
N, K = map(int, input().split())
A = [int(i) - 1 for i in input().split()]

s = set()
s.add(0)
cur = 0
num = 0
d = defaultdict(int)
d[0] = 0
ls = [0]
for i in range(K):
    if A[cur] not in s:
        cur = A[cur]
        num += 1
        d[cur] = i+1
        ls.append(cur)
        s.add(cur)
    else:
        cur = A[cur]
        num += 1
        edges_heiro = num - d[cur]
        nokori = K - num
        print(ls[d[cur] + nokori%edges_heiro] + 1)
        sys.exit()
print(cur + 1)
