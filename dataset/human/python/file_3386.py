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
S = []
if N == 1:
  print(0)
  exit(0)
fac = factorization(N)
for i in range(len(fac)):
  S.append(fac[i][1])
ans = 0
for i in range(len(S)):
  for j in range(1,S[i] + 1):
    if S[i] - j < 0:
      break
    ans += 1
    S[i] -= j
print(ans)
