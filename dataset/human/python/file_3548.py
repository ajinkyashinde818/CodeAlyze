from math import floor

arr = []

def factorization(n):
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

    
    
n = int(input())
if n == 1:
  print(0)
  exit()
  
factorization(n)
ans = 0

for prime,power in arr:
  ans += floor((-1+(1+8*power)**0.5)/2)
  
print(ans)
