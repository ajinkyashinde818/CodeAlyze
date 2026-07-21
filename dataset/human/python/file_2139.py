import collections
n=int(input())
S=input()
alphabet=[chr(ord('a') + i) for i in range(26)]
kaisu=collections.Counter(S)
ans=1
for i in alphabet:
	if kaisu[i]!=0:
		ans*=kaisu[i]+1
	ans=ans%(10**9+7)
ans-=1
print(ans)
