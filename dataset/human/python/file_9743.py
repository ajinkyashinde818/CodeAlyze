import sys
N, K = map(int, input().split()) #N: 町の数, K: ちょうどこの回数でたどり着く町

visited = [False for _ in range(N)]

A = list(map(lambda n: int(n)-1, input().split()))
tmp = 0 #次に訪れる番号
visited[0] = True
#cnt = 0 #テレポートの回数
log = [0] #テレポートの記録

for i in range(1, K+1):
    tmp = A[tmp]
    if visited[tmp]:
        start = log.index(tmp)
        break

    visited[tmp] = True
    log.append(tmp)

if i == K:
    print(tmp+1)
else:
    loop = log[start:i+1]
    period = len(loop)
    remain = K - i
    print(loop[remain%period] + 1)
