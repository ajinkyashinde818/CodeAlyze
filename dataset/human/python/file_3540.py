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

f=factorization(int(input())) 
ans=0
for list in f:
  if list[0]==1:
    continue
  m=list[1]
  n=int((2*m)**(1/2))
  while True:
    if n*(1+n)>2*m:
      n-=1
      break
    n+=1

  ans+=n
print(ans)
