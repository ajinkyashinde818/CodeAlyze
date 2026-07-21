N=int(input())
if N==1:
    print(0)
    exit()

def primeryNum(n):
    border=int(n**0.5)+1
    ary=list(range(int(n**0.5)+2))
    ary[1]=0
    for a in ary:
        if a>border: break
        elif a==0: continue
        for i in range(a*2,int(n**0.5)+2,a):
            ary[i]=0           
    return ary

primeryNumL=primeryNum(N)
# print(primeryNumL)
ans=0
N_=N
for x in primeryNumL:
    if x==0 or N%x!=0:
        continue
    n=N
    cnt=0
    while n%x==0:
        cnt+=1
        n/=x
    N_//=x**cnt
    buf=cnt-1
    res=1
    # print(x,cnt)
    for i in range(2,cnt+1):
        if buf<i:
            break
        buf-=i
        res+=1
    ans+=res
if N_>1:
    ans+=1
print(ans)
