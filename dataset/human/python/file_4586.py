import math
N = int(input())

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

  
table = factorization(N)

if N == 1:
  print(0)
else:
  ans = 0
  for a,b in table:
    cand = int(math.sqrt(2*b))
    cnt = 0
    for i in range(max(0,cand-10),cand+10):
      if 2*b >= i*(i+1):
        cnt=i
      else:
        break
    ans += cnt
  print(ans)
