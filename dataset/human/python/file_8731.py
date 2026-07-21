import sys
k, n = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
L=[]
for i in range(0, n-1):
    L.append(abs(A[i+1]-A[i]))
L.append(k-A[-1]+ A[0])
#print(L)
print(sum(L)-max(L))
