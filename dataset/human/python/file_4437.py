import math
import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

def factorization(n):
    arr = []
    for i in range(2,int(math.sqrt(n))+1):
        cnt = 0
        if n % i == 0:
            while n % i ==0:
                n //= i
                cnt +=1
            #arr.append([i,cnt])
            arr.append(cnt)
    if n != 1:
        #arr.append([n,1])
        arr.append(1)
    return arr
N = int(read())
arr = factorization(N)
ans = 0 
for a in arr:
  for i in range(1,50):
    if a-i>=0:
      a -=i
      ans +=1
    else:
      break
print(ans)
