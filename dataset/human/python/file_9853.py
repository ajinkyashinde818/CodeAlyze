N,K=map(int, input().split())
A = list(map(int, input().split()))

A0=list(range(N))

def calc_zero(n):
    return n * 0

A0 = list(map(calc_zero, A0))

temp=0
tempv=[]

for i in range(K):
  if A0[temp]>=1:
    loop=i-A0[temp]
    t=(K-A0[temp])%loop
    temp=tempv[A0[temp]+t-1]
    break
  else:
    A0[temp]=i
    temp=A[temp]-1
    tempv.append(temp)

print(temp+1)
