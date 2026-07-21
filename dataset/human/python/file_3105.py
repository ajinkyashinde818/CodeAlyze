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
for i in range(len(a)):
  tmp=0
  for j in range(1,50):
    tmp+=j
    if a[i][1] >= tmp:
      ans += 1
if n==1:
  print(0)
else:
  print(ans)
