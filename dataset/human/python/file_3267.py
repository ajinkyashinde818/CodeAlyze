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
if N == 1:
  print(0)
  exit(0)
f = factorization(N)
#print(f)
ans = 0
amari_cnt = 0
for a,b in f:
  wk = b
  tempc = 1
  while wk  - tempc >= 0:
    wk -= tempc
    ans += 1
    tempc += 1

print(ans)
