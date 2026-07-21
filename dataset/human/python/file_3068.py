from decimal import Decimal as de
n=int(input())
def factorization(n):
    factor=[]
    p=[]
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            factor.append(i)
            p.append(cnt)
    if temp!=1:
        factor.append(temp)
        p.append(1)
    if len(factor)==0:
        factor.append(n)
        p.append(1)
    return factor,p

ans=0
for i in [k for j,k in zip(factorization(n)[0],factorization(n)[1]) if j!=1]:
  ans+=((de(1)+de(8)*de(i))**de('0.5')-de(1))//de(2)
print(int(ans))
