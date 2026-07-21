from collections import defaultdict
N,M = map(int,input().split())
dic = defaultdict(list)
for i in range(M):
    a,b = map(int,input().split())
    dic[a].append(b)
def solve(dic):
    for s in dic[1]:
        for m in dic[s]:
            if m == N:
                return True
if solve(dic): print('POSSIBLE')
else: print('IMPOSSIBLE')
