import sys
N,K=list(map(int,input().split()))
A=list(map(int,input().split()))
p = 1
B = [-1]*N
B[0] = 0
count = 1
while K >= count:
	p = A[p-1]
	if B[p-1] != -1:
		break
	B[p-1] = count
	count += 1
if K < count:
	print(p)
	sys.exit()
K -= count
K = K % (count-B[p-1])
for i in range(K):
	p = A[p-1]
print(p)
