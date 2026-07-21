"""nを素因数分解"""
"""2以上の整数n => [[素因数, 指数], ...]の2次元リスト"""

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
# print(factorization(N))

ans = 0
for a, b in factorization(N):
  if a == 1:
    print(0)
    exit()
  # print()
  # print((a, b))
  t = 0
  for i in range(1, 10+b):
    t += i
    if t > b:
      ans += (i-1)
      break

print(ans)
