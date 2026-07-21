import math
N=int(input())
n=N
p=2
dp=1
thrP=math.sqrt(N)
dcmp={}
while n>1:
    if n%p==0:
        dcmp[p]=1+(dcmp[p] if p in dcmp else 0)
        n//=p
    else:
        p+=dp
        dp=2
    if p>thrP:
        if n>1:
            dcmp[n]=1
        break
cnt=0
for k,v in dcmp.items():
    i=1
    while True:
        dcmp[k]-=i
        if dcmp[k]<0:
            break
        i+=1
        cnt+=1

print(cnt)
