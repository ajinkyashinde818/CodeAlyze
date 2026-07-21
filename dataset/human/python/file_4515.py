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
a = factorization(N)
cnt = 0
for i in a:
  temp = i[1]-1
  d = 2
  while temp>=d:
    temp -= d
    d += 1
  cnt+=d-1
print(cnt)
