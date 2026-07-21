import math

D,G = map(int,input().split())
P = []
C = []
for _ in range(D):
    p,c = map(int,input().split())
    P.append(p)
    C.append(c)

ans = sum(P)
for i in range(2**D - 1):
    inSolve = -1
    score_tmp = 0
    solved = 0
    for j in range(D):
        if (i>>j)%2 == 1:
            score_tmp += (j+1)*100*P[j]+C[j]
            solved += P[j]
        else:
            inSolve = max(j,inSolve)
    if score_tmp < G and inSolve != -1:
        if math.ceil((G-score_tmp)/((inSolve+1)*100)) <= P[inSolve]:
            ans = min(ans,solved + math.ceil((G-score_tmp)/((inSolve+1)*100)))
    elif score_tmp >= G:
        ans = min(ans,solved)
print(ans)
