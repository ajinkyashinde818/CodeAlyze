n = int(input())
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

if n == 1:
  print(0)
else:
  arr = factorization(n)
  c = 0
  for e in arr:
    now = 0
    while e[1] > now:
      now += 1
      e[1] -= now
    c += now
  print(c)
