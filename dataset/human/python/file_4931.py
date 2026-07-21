import sys
input=sys.stdin.readline
n=int(input())
x_list=list(map(int,input().split()))
INF=10**9+7
def modinv(a,m):
    b=m
    (x,lastx)=(0,1)
    (y,lasty)=(1,0)
    while not b==0:
        q=a//b
        (a,b)=(b,a%b)
        (x, lastx) = (lastx - q * x, x)
        (y, lasty) = (lasty - q * y, y)
    return lastx%m
ans=0
s=1
for i in range(n-1):
    s=s*(i+1)
    s=s%INF
for i in range(n-1):
    x=modinv(i+1,INF)
    ans=(ans+s*x*(x_list[n-1]-x_list[n-2-i]))%INF
sumx=[]
isumx=[]
sx=0
isx=0
for i in range(n-1):
    sx=(sx+x_list[i])%INF
    isx=(isx+x_list[n-2-i])%INF
    sumx.append(sx)
    isumx.append(isx)
for i in range(n-2):
    x=modinv(i+1,INF)
    y=modinv(i+2,INF)
    ans=(ans+s*x*y*(isumx[i]-sumx[i]))%INF
print(ans)
