n=int(input())
ans=0

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

temp=factorization(n) 

if n==1:
  print(0)
else:
  i=0
  j=0
  while i<len(temp):
    if temp[i][1]>=j+1:
      temp[i][1]=temp[i][1]-(j+1)
      j=j+1
      ans=ans+1
    else:
      i=i+1
      j=0
  print(ans)
