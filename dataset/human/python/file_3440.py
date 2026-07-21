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

  return arr

arr = factorization(int(input()))

ans = 0
for p in arr:
  i = 1
  while p[1] >= i:
    ans += 1
    p[1] -= i
    i += 1
    
print(ans)
