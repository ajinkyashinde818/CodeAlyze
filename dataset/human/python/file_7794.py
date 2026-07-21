import math

def f(n,k,s):
  if s== 10**9:
    return [s if i<k else s-1 for i in range(n)]
  return [s if i<k else s+1 for i in range(n)]
  
    

n,k,s= map(int,input().split())

ans = f(n,k,s)

s= ""

for a in ans:
  s += str(a)+" "
  
print(s)
