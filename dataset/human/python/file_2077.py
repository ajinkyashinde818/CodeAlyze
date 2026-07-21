from collections import defaultdict

N=int(input())
S=input()
INF=int(1e9+7)
dict=defaultdict(int)
for i in S:
    dict[i]+=1
l=list(dict.values())
ans=1
for i in l:
    ans*=(i+1)
    ans%=INF
print(ans-1)
