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
a=factorization(n)
ans=0
if a[0][0]==1:
  print(0)
else:
  for i in a:
    now=(2*i[1])**0.5
    now=int(now//1)
    while now*(now+1)<=2*i[1]:
      now+=1
    ans+=now-1
  print(ans)
