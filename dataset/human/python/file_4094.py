from collections import Counter

N = int(input())
pf={}

for i in range(2,int(N**0.5)+1):
    while N%i==0:
        pf[i]=pf.get(i,0)+1
        N//=i
if N>1:pf[N]=1

value_ = Counter(list(pf.values()))
result = 0
for k,v in value_.items():
    if k == 1:
        result += v
    else:
        for i in range(k+1):
            if i * (i+1) / 2 > k:
                result += (i-1) * v
                break
print(result)
