N=int(input())
def PrimeFactor(n):
    ret=[]
    for i in range(2,int(-(-n**0.5//1))+1):
        if i!=2 and i%2==0:
            continue
        cnt=0
        while n%i==0:
            cnt+=1
            n//=i
        if cnt!=0:
            ret.append([i,cnt])
    if n!=1:
        ret.append([n,1])
    return ret
L = PrimeFactor(N)
ans=0
for l in L:
    x = l[1]
    temp=1
    while x>=temp:
        ans+=1
        x-=temp
        temp+=1
print(ans)
