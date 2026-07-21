import sys
def input():
  return sys.stdin.readline().rstrip()

N=int(input())
S=input()

MOD=10**9+7
num=[0]*30

for c in S:
  num[ord(c)-ord("a")]+=1

ans=1
for i in range(26):
  ans*=num[i]+1
  ans%=MOD

print((ans+MOD-1)%MOD)
