N=int(input())
S=list(input())
a=[0]*N
for i in range(N):
    a[i]=ord(S[i])-96
from collections import Counter
b=Counter(a)
c=b.most_common()
ans=1
for i in range(len(c)):
    ans*=(c[i][1]+1)
print((ans-1)%(10**9+7))
