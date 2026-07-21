import numpy as np

n=int(input())
if n==1:
  print(0)
else:
  def factorization(n):
      arr = []
      temp = n
      for i in range(2, int(-(-n**0.5//1))+1):
          if temp%i==0:
              cnt=0
              while temp%i==0:
                  cnt+=1
                  temp //= i
              arr.append([i, cnt])
 
      if temp!=1:
          arr.append([temp, 1])
 
      if arr==[]:
          arr.append([n, 1])
 
      return arr
 
  y=factorization(n)
  def judge(y):
    i=1
    while np.arange(i+2).sum()<=y:
      i+=1
    return i
  ans=0
  for i in range(len(y)):
    ans+=judge(y[i][1])
  print(ans)
