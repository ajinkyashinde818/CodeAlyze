import math
D,G = map(int, input().split())
L=[[0,0] for i in range(D)]

for i in range(D):
    L[i][0],L[i][1]=map(int, input().split())
MAP=[0]*(D+1)
C=[[0,0] for i in range(D)]
for i in range(D):
    C[i][1]=(i+1)
    C[i][0]=L[i][0]*(i+1)*100
C=sorted(C,reverse=True)

a=10**10
while(MAP[-1]==0):
    for j in range(D):
        if MAP[j] > 1:
            MAP[j] -= 2
            MAP[j+1]+=1 
    s=0
    c=0
    for j in range(D):   
        if(MAP[j]!=0):
            s+=L[j][0]*(j+1)*100
            s+=L[j][1]
            c+=L[j][0]
    if(c<a):
        if(s<G):
            for i in range(D):
                if(MAP[C[i][1]-1]==0):
                    t=G-s
                    if(C[i][0]>t):
                        c+=math.ceil(t/(C[i][1]*100))
                        s+=C[i][1]*100*math.ceil(t/(C[i][1]*100))
                    break
        if(s>=G):
            a=min(a,c)
            #print(a,MAP)
    MAP[0]+=1
print(a)
