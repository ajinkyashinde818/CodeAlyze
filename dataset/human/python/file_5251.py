import sys
def MI(): return map(int,sys.stdin.readline().rstrip().split())


N,M = MI()
d1 = {}  # d1[i] = 島1と島iの間に定期便が存在するか
d2 = {}  # d1[i] = 島Nと島iの間に定期便が存在するか
for i in range(1,N+1):
    d1[i] = 0
    d2[i] = 0
for _ in range(M):
    a,b = MI()
    if a == 1:
        d1[b] = 1
    if b == N:
        d2[a] = 1
for i in d1.keys():
    if d1[i] == d2[i] == 1:
        print('POSSIBLE')
        break
else:
    print('IMPOSSIBLE')
