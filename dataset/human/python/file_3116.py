import math
N = int(input())
pf={}
m = N
for i in range(2,int(m**0.5)+1):
    while m%i==0:
        pf[i]=pf.get(i,0)+1
        m//=i
if m>1:pf[m]=1

total = 0
for v in pf.values():
    val = int((-1 + math.sqrt(1 + 8 * v))/2)
    total += val
print(total)
