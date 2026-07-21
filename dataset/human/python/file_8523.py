import sys

(K,N)=map(int,input().split())

buf=input()
A=list(map(int,buf.split()))

diff_max=A[0]+K-A[N-1]
imax=N
for i in range(N-1):
    d=A[i+1]-A[i]
    if d>diff_max:
        diff_max=d
        imax=i

print(K-diff_max)
