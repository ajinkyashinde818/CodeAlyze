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
ans = 0
N = int(input())
f = factorization(N)
for pair in f:
  p = pair[0]
  e = pair[1]
  i = 1
  while(e-i>=0):
    e = e - i
    i = i  + 1
    ans = ans + 1
if N == 1:
  ans = 0
print(ans)
