import numpy as np
D,G=list(map(int,input().split()))
p=np.zeros(D)
c=np.zeros(D)
for i in range(D):
    a,b=list(map(int,input().split()))
    p[i]=a
    c[i]=b
    
def solve(x):  
    score=0
    cost=0
    no_use=0
    
    b=str(format(x,'010b'))
    for i in range(1,D+1):
        if b[-i]=="1": #全問解答する
            score+=100*i*p[i-1]+c[i-1]
            cost+=p[i-1]
        else:
            no_use=i-1

    if score<G: #足りていない場合
        no_solve=p[no_use]-1
        while(no_solve!=0):
            score+=100*(no_use+1)
            cost+=1
            if score>=G:
                return cost
            no_solve-=1
                
    if score<G:
        return 10**9+7
    return cost

min_cost=10**9+7
for x in range(2**D):
    cost=solve(x)
    if cost<min_cost:
        min_cost=cost
print(int(min_cost))
