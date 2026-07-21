from sys import stdin, stdout  

K, N = [int(c) for c in input().split()]
A = [int(c) for c in input().split()]
dist=[]
for i in range(0,N-1):
    dist.append(A[i+1]-A[i])
dist.append(abs(A[0]-A[-1]+K))

m=max(dist)
for idx,val in enumerate(dist):
    if(val==m):
        dist[idx]=0
        break
print(sum(dist))
