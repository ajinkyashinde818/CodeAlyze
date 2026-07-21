D,G = map(int,input().split())
PC = [list(map(int,input().split())) for i in range(D)]

ans = float("inf")
bi = [0,1]
import itertools

for i in list(itertools.product(bi, repeat=D)):
    tmp = 0
    p = 0
    for j in range(D):
        if i[j] == 1:
            p += PC[j][1]
            p += PC[j][0]*100*(j+1)
            tmp += PC[j][0]
    for j in range(D):
        k = D-1-j
        if p >= G:
            break
        if i[k] == 0:
            tmp += min(PC[k][0]-1,-(-(G-p)//(100*(k+1))))
            p += min(PC[k][0]-1,-(-(G-p)//(100*(k+1)))) * (100*(k+1))
            
    if ans > tmp and p>=G:
        ans = tmp


print(ans)
