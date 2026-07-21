s=list(input())
x,y=map(int,input().split())
f=0
t=0
s.append('T')
n=len(s)
xl=[]
yl=[]
for i in range(n):
    if s[i]=='F':
        f+=1
    else:
        if f>0:
            if t%2==0:
                if t==0:
                    x-=f
                else:
                    xl.append(f)
            else:
                yl.append(f)
            f=0
        t+=1
def solve(x,l):
    n=len(l)
    k=2*8000+1
    dp=[[-1 for p in range(k)] for q in range(n+1)]
    dp[0][k//2]=0
    for i in range(1,n+1):
        for j in range(k):
            if dp[i-1][j]>=0:
                dp[i][j-l[i-1]]=1
                dp[i][j+l[i-1]]=1
                #print(j)
    if dp[-1][x+k//2]>=0:
        return True
    else:
        return False
if solve(x,xl) and solve(y,yl):
    print('Yes')
else:
    print('No')
#print(xl,yl)
