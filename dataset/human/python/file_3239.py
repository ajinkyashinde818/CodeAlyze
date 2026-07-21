import math

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

N = int(input())

ans = 0
c = factorization(N)  
#print(c)
for i in range(len(c)):
  A = c[i][1]
  if(c[i][0] == 1):
    n = 0
  else:
    n = int((-1+math.sqrt(1+8*A))/2 + 0.01) 
  ans += n
  
print(ans)
