import math

n=int(input())
s=input()

l=[]
for i in range(26):
	l.append(0)

for i in range(n):
	l[ord(s[i])-97]+=1

p=1000000007
ans=1
for i in range(26):
	ans*=(l[i]+1)%p

ans=ans%p

ans-=1

print(ans)
