D,G = map(int,input().split())
P = [0]*D
C = [0]*D
for i in range(D):
    P[i],C[i] = map(int,input().split())

def count(bit):
    cnt = 0
    point = 0
    i = 0
    comp = [False]*D
    while bit > 0:
        if bit&1:
            cnt += P[i]
            point += P[i]*100*(i+1) + C[i]
            comp[i] = True
        i += 1
        bit = bit >> 1
    if point >= G:return cnt
    for i in range(D-1,-1,-1):
        if comp[i]:continue
        if point + 100*(i+1)*(P[i]-1) < G:
            cnt += P[i] - 1
            point += 100*(i+1)*(P[i]-1)
        else:
            cnt += (G-point-1)//(100*(i+1)) + 1
            return cnt
    return 1e100

ans = 1e100
for i in range(2**D):
    # i:下からj桁目は100j問題でc-bonusを取るか
    ans = min(ans, count(i))
print(ans)
