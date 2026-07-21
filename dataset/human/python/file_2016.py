import sys


N=int(input())
s=input()
def find(s):
    dic={}
    for x in s:
        if x in dic:
            dic[x]+=1
        else:
            dic[x]=1

    MOD=10**9+7
    ans=1
    for x in dic:
        ans*=dic[x]+1
        ans%=MOD
    return (ans-1)%MOD

print(find(s))
