def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)

    if arr==[]:
        arr.append(1)

    return arr

n = int(input())
if n == 1:
  print(0)
  exit()
f = factorization(n)
ans = 0
sum_list = [1, 3, 6, 10, 15, 21, 28, 36, 45]
for i in f:
  for j, m in enumerate(sum_list):
    if i < m:
      ans += j
      break
print(ans)
