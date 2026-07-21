import math

D,G=map(int,input().split())


score=[None]*D
for i in range(D):
    score[i]=list(map(int,input().split()))


import itertools
bitlist=list(itertools.product((0,1),repeat=D))

def xx(a):
    XX=[0 for i in range(D)]
    for i in range(len(a)):
        if a[i]==1:
            XX[i]=score[i][0]
    return XX


def scoresolve(X):
    ANS=0
    for i in range(len(X)):
            ANS+=X[i]*(i+1)*100
            if X[i]==score[i][0]:
                ANS+=score[i][1]

    return ANS





ANS=100000
for bit in bitlist:
    ii=xx(bit)
    if scoresolve(ii)>=G:
        ANS=min(ANS,sum(ii))
    else:
        j=D-ii[::-1].index(0)-1
        if G-scoresolve(ii)<=(j+1)*100*score[j][0]:
            ANS=min(ANS,sum(ii)+math.ceil((G-scoresolve(ii))/(j+1)/100))

print(ANS)
