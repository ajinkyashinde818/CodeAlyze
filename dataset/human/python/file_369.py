import numpy as np

def rev(i):
    if i==0:
        return 1
    return 0

N=int(input())
A=np.array(list(map(int,input().split())))
s=[]
for i in range(N):
    if A[i]>=0:
        s.append(1)
    else:
        s.append(0)

s[::-1]
for i in range(N-1):
    if s[i]==0:
        s[i]=1
        s[i+1]=rev(s[i+1])
if np.sum(s)!=N:
    ans=np.sum(np.abs(A))-2*np.min(np.abs(A))
    print(ans)
else:
    print(np.sum(np.abs(A)))
