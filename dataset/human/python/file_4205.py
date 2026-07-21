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

ans = 0

n = int(input())
for i,j in factorization(n):
  if i == 1:
    continue
  for k in range(int((2 * j)**0.5), 0 ,-1):
    if k*(k+1) <= 2 * j and (k+1)*(k+2) >= 2 * j:
      ans += k
      break
print(ans)
