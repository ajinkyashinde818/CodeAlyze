def f(i,n):
  ans =0
  cnt = i
  while n%cnt == 0:
    n//=cnt
    cnt*=i
    ans +=1
  while n%i ==0:
    n//=i
  return n,ans

n = int(input())
i = 2
ans = 0
while i <= int(n**0.5)+1:
  if n%i ==0:
    n,a = f(i,n)
    ans += a
  i += 1
  
if n >1:
  ans += 1
print(ans)
