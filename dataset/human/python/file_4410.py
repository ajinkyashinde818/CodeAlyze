import sys

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
fs = factorization(N)

if N == 1:
  print(0)
  sys.exit()

ans = 0
for f in fs:
  for e in range(1, f[1] + 1):
    z = f[0] ** e
    if N % z == 0:
      N //= z
      ans += 1

print(ans)
