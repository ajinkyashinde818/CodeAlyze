import itertools
import math

D,G=map(int,input().split())
p=[0]*D
c=[0]*D

for i in range(D):
    p[i],c[i]=map(int,input().split())
    
ans=10**7

for ite in itertools.product([0,1], repeat=D):
    temp=0
    tn=0
    for i in range(len(ite)):
        temp+=ite[i]*(c[i]+100*(i+1)*p[i])
        tn+=p[i]*ite[i]
    if temp>=G:
        ans=min(ans,tn)
    else:
        for i in range(len(ite)-1,-1,-1):
            if ite[i]==0:
                if math.ceil((G-temp)/((i+1)*100)) <=p[i]-1 :#その難易度の問題を1問残しで埋めて目標に届くなら:
                    ans=min(ans,tn+math.ceil( (G-temp)/((i+1)*100) ) )
                else:
                    temp+=(i+1)*100*(p[i]-1)
                    tn+=p[i]-1
                    
print(int(ans))
