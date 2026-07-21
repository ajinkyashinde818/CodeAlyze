import math,sys
ans=0
def factorization(n):
    num=0
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
            num=num+1
    if temp!=1:
        arr.append([temp, 1])
    if arr==[]:
        arr.append([n, 1])
    return arr,num
def kirisute(n):
    p=(-1+math.sqrt(1+8*n))/2
    q=math.floor(p)
    return q
N=int(input())
if N==1:
  print(0)
  sys.exit()
soinsuu,jigen=factorization(N)
for i in range(len(soinsuu)):
  ans=ans+kirisute(soinsuu[i][1])
print(ans)
