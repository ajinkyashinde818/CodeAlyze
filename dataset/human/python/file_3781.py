def fac(n):
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


N=int(input())
ans=0
A=fac(N)
for i in range(len(A)):
  p=2*A[i][1]
  q=p**0.5
  if A[i][0]==1:
    ans+=0
  elif type(q)=="int":
    ans+=q-1
  else:
    q=q//1
    if q*(q+1)<=p:
      ans+=q
    else:
      ans+=q-1
print(int(ans))
