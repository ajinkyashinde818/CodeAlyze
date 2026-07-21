import sys
from collections import deque

input = sys.stdin.readline
N, K = map(int, input().split())
A = list(map(int, input().split()))

visited = set()
q = deque()
q.append(1)

root = []
while q:
    pos = q.pop()
    if pos in visited:
        start = root.index(pos)
        s_len = len(root[:start])
        l_len = len(root[start:])
        break
    visited.add(pos)
    root.append(pos)

    q.append(A[pos-1])

if K <= s_len:
    print(root[K])
else:
    r = (K - s_len) % l_len
    print(root[start+r])
