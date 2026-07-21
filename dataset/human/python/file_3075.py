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
s=factorization(n)
ans=0
for i in s:
  k=i[0]
  l=i[1]
  p=1
  while l>=0:
    ans+=1
    l-=p
    p+=1
  ans-=1
if n==1:
  print(0)
else:
  print(ans)
