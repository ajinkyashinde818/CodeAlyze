def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))
N,K=MI()
A=[0]+LI()
c=1
turn=[-1]*(N+1)
for k in range(K):
  if turn[c]!=-1:
    T=k-turn[c]
    bias=turn[c]
    break
  turn[c]=k
  c=A[c]
else:
  print(c)
  exit()
K-=bias
K%=T
K+=bias
c=1
for k in range(K):
  c=A[c]
print(c)
