from bisect import bisect_right,bisect

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


def triangle(n):
  return n*(n+1)//2

T = [ triangle(i) for i in range(1, 10**6)]

#print(factorization(N))

ans = 0
for _, i in factorization(N):
  ans += bisect_right(T, i) 

  
  
if N == 1:
  ans = 0
print(ans)
