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

total = 0
arr = factorization(n)
for [insu, num] in arr:
  if insu == 1:
    break
  i = 1
  while num >= 0:
    num -= i
    total += 1
    i += 1
  total -= 1
print(total)
