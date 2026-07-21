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
ans = 0
if n == 1:
  print(0)
  quit()
for f in factorization(n):
  count = 0
  for i in range(1,f[1]+1):
    count += i
    if count <= f[1]:
      ans += 1
    else:
      break
print(ans)
