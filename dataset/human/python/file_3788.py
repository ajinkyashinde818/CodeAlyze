import math
n = int(input())
count = 0
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
kon = math.sqrt(n)
kon = math.floor(kon)+1
a = factorization(n)
sc = len(a)
if n==1:
  print(0)
else:
  for i in range(sc):
    for j in range(kon):
      if a[i-1][1]>=j+1:
        count=count+1
        a[i-1][1]=a[i-1][1]-j-1
  print(count)
