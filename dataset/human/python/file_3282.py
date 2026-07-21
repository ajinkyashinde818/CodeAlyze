from math import sqrt

pf={}
m=int(input())
for i in range(2,int(m**0.5)+1):
    while m%i==0:
        pf[i]=pf.get(i,0)+1
        m//=i
if m>1:pf[m]=1

ans =0
for value in pf.values():
    ans += int((sqrt(value*8+1)-1)/2)
print(ans)
