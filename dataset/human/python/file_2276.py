import math

D, G = list(map(int, input().split()))
p = [list(map(int, input().split())) for _ in range(D)]
ResMin = 1000

for i in range(2**D):
    numProb = 0
    numPoint = 0
    maxProb = 0
    bonusflag = [0]*D
    for j in range(D):
        if ((i >> j) & 1):
            bonusflag[D-1-j] = 1

    for k in range(D):
        if bonusflag[k] == 1:
            numProb += p[k][0]
            numPoint += (100*(k+1)*p[k][0] + p[k][1])
        else:
            maxProb = k
    if numPoint < G:
        sub = math.ceil((G-numPoint)/(100*(maxProb+1)))
        if sub <= p[maxProb][0]:
            numProb += sub
        else:
            continue
    if numProb < ResMin:
        ResMin = numProb

print(ResMin)
