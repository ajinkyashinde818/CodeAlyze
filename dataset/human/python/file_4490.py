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

n=int(input())
x=factorization(n)
ans=0

if n==1:
  print(0)
  exit()
for i in range(len(x)):
  p=x[i][1]
  j=1
  while True:
    if p>=j:
      p-=j
      ans+=1
      j+=1
    if p<j:
      break
print(ans)
