mod=998244353

def cmb(n,r):
  if r<0 or r>n:
    return 0
  return (g1[n]*g2[r]*g2[n-r])%mod

g1=[1,1]
g2=[1,1]
inv=[0,1]
for i in range(2,100003):
  g1.append((g1[-1]*i)%mod)
  inv.append((-inv[mod%i]*(mod//i))%mod)
  g2.append((g2[-1]*inv[-1])%mod)
K,N=map(int,input().split())
C=[0]*(2*K)
for i in range(K):
  for j in range(i+1,K):
    C[i+j]+=1
for i in range(2*K-1):
  P=0
  if i&1:
    for j in range(C[i]+1):
      P=(P+cmb(K+N-2*C[i]-1,N-j)*pow(2,j,mod)*cmb(C[i],j))%mod
  else:
    for k in range(2):
      for j in range(C[i]+1):
        P=(P+cmb(K+N-2*C[i]-2-k,N-j-k)*pow(2,j,mod)*cmb(C[i],j))%mod
  print(P)
