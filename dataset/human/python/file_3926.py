def factorization(n):
  arr = []
  temp = n
  for i in range(2, int(n**0.5)+1):
    if temp%i==0:
      cnt=0
      while temp%i==0:
        cnt+=1
        temp /= i
      arr.append([i, cnt])
      
  if temp!=1:
    arr.append([temp, 1])
    
  if arr==[]:
    arr.append([n, 1])
    
  return arr

a = factorization(int(input()))
b = [1, 3, 6, 10, 15, 21, 28, 36, 45]

ans = 0

if len(a) == 1 and a[0][0] == 1:
  print(0)
  exit()
  
for i in a:
  for j in range(len(b)):
    if i[1] < b[j]:
      ans+=j
      break
    
print(ans)
