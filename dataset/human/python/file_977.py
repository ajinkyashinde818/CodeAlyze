import math
N = int(input())
S = input()
mod = 10**9+7
if(not (S[0]==S[-1]=='B')):
    print(0)
else:
    d = []
    cumu = [[0]*2 for _ in range(N*2)]
    cnt = 1
    for ind,s in enumerate(S):
        if(ind==0):
            d.append(0)
            cumu[0][0]+=1
        else:
            if(S[ind-1]==s):
                d.append(1-d[-1])
            else:
                d.append(d[-1])
            cumu[ind][0] = cumu[ind-1][0]
            cumu[ind][1] = cumu[ind-1][1]
            cumu[ind][d[-1]]+=1
            if(d[-1]==1):
                cnt *= (cumu[ind-1][0]-cumu[ind-1][1])
                cnt %= mod
    if(cumu[-1][0]!=cumu[-1][1]):
        cnt=0
    print((math.factorial(N)*cnt)%mod)
