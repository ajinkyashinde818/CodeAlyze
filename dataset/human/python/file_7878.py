from math import ceil
N, K, S = map(int,input().split())

fill = 10**9
if S == 10**9: fill-=2
if N == K:
  for i in range(K): print(S,end=" ")
elif S == 1:    
  for i in range(K): print(1,end=" ")
  for i in range(N-K): print(fill,end=" ")  
else:
  for i in range(ceil(K/2)): 
    print(S-1,end=" ")
    print(1,end=" ")
  if K%2 == 0: 
    print(S-1,end=" ")  
    for i in range(N-ceil(K/2)*2-1):
      print(fill,end=" ")
  else:
    for i in range(N-ceil(K/2)*2):
      print(fill,end=" ")
