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

a=int(input())
if a==1:
  print(0)
else:
  lis=factorization(a)
  ans=0
  for i in range(len(lis)):
    k=1
    while lis[i][1]>=k:
      lis[i][1] -= k
      k+=1
      ans+=1
  print(ans)
