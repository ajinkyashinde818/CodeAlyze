import sys
def inpl(): return list(map(int, sys.stdin.readline().split()))
N, K = map(int, sys.stdin.readline().split())
A = inpl()
dic = {}
for i in range(N):
    dic[i+1] = A[i]
i = 1
visit = []
visit_set = set()
while i not in visit_set:
    visit.append(i)
    visit_set.add(i)
    i = dic[i]
find = visit.index(i)
if K < find:
    print(visit[K])
else:
    root = visit[find:]
    length = len(root)
    K = (K-find) % length
    print(root[K])
