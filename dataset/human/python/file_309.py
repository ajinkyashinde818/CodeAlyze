import sys
N=int(input())
A=[int(x) for x in sys.stdin.readline().split()]

abssum=0
negative=0
mi=100000000000000
for i in range(N):
	if A[i]<0:
		negative+=1
	abssum+=abs(A[i])
	mi=min(mi,abs(A[i]))

if negative%2==1:
	abssum-=2*mi
print(abssum)
