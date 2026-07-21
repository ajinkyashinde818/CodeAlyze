from bisect import bisect_left, bisect_right

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
if N == 1:
  print(0)
  exit()
Fact = factorization(N) 

Counter=[1]
for i in range(2,10):
  Counter.append(Counter[-1]+i)


ans = 0
tmp = 0
for i in range(len(Fact)):
  tmp = Fact[i][1]
  ans += bisect_right(Counter, tmp)

print(ans)
