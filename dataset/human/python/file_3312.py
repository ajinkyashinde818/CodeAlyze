from collections import Counter
import math
n=int(input())

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)

    return a

s=dict(Counter(prime_factorize(n)))
#print(s)
sum_ans=0
for i in s.values():
  
  if i==1:
    sum_ans+=1
    
  else:
    k=1
    while i>0:
      i-=k
      k+=1
      #print(i)
      if i<0:
        break
      sum_ans+=1
      
print(sum_ans)
