import numpy as np

N,M=map(int,input().split())

A=[list(map(int,list(input().replace('.','0').replace('#','1')))) for _ in range(N)]
B=[list(map(int,list(input().replace('.','0').replace('#','1')))) for _ in range(M)]

A,B=map(np.array,(A,B))

for i in range(N-M+1):
  for j in range(N-M+1):
    if (A[i:i+M,j:j+M] == B).all():
      print('Yes')
      exit()

print('No')
