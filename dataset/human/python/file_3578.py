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

arr = factorization(N)
cdic = {}
for ar in arr:
  cdic[ar[0]] = 1
  sum = 1
  while sum+cdic[ar[0]]+1 <= ar[1]:
    #print(cdic[ar[0]], sum)
    sum += cdic[ar[0]]+1
    cdic[ar[0]] += 1
ans = 0
for c in cdic.values():
  ans += c

if N == 1:
  print(0)
else:
  print(ans)
