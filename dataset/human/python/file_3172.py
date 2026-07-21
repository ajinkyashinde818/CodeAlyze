N=int(input())
if N==1:
  print(0)
  exit()
  
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

a=factorization(N) 
A=[]
d=0
for i in range(1,50):
  d+=i
  A.append(d)
import bisect
cnt=0
for x,y in a:
  e=bisect.bisect_right(A,y)
  cnt+=e
print(cnt)
