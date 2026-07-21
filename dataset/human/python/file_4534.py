def factorization(y):
    arr = []
    temp = y
    for i in range(2, int(-(-y**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])
    if arr==[]:
        arr.append([y, 1])
    return arr
n=int(input())
if n==1:
  print(0)
  exit()
ans=0
l=factorization(n)
for i,j in l:
    if j<=2:
      ans+=1
    else:
      t=1
      while j:
        if j<t:
          break
        ans+=1
        j-=t
        t+=1           
print(ans)
