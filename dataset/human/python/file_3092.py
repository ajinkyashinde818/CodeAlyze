import bisect
import math
import sys
 
jd = []
for i in range(1,50) :
  jd.append((1+i)*i//2)
  
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

n = int(input())

if n == 1 :
  print(0)
  sys.exit()

p = factorization(n)

ans = 0
for i in p :
  c = i[1]
  ans += bisect.bisect_right(jd, c)
  
print(ans)
