import sys

N=int(input())
if N==1:
	print(0)
	sys.exit()

def factorization(n):
	arr=[]
	temp=n
	for i in range(2,int(n**0.5)+1):
		if temp%i==0:
			cnt=0
			while temp%i==0:
				cnt+=1
				temp//=i
			arr.append([i,cnt])
	if temp!=1:
		arr.append([temp,1])
	if arr==[]:
		arr.append([n,1])
	return arr

a=factorization(N)
ans=0
for i in range(len(a)):
	if a[i][1]!=0:
		cnt=1
		while a[i][1]-cnt>=0:
			a[i][1]-=cnt
			ans+=1
			cnt+=1
print(ans)
