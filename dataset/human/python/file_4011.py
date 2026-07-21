def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

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

factorization(24) 

import sys
N=int(input())
if(N==1):
  print(0)
  sys.exit()
div = make_divisors(N)
div.remove(1)
new_div=[]
for k in div:
  jud=factorization(k) 
  if(len(jud)==1):
    new_div.append(k)
ans=0

for i in new_div:
  if(N%i==0):
    N=N/i
    ans+=1
  if(N==1):
    print(ans)
    sys.exit()
print(ans)
