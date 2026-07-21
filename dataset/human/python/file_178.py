def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(input())
def S(): return list(input())
r,g,b,n=IL()
ans=0
for i in range(0,n+1):
    for j in range(0,n+1):
        if (n-i*r-j*g)%b==0 and n-i*r-j*g>=0:
            ans+=1
            
print(ans)
