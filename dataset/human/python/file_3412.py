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

n = int(input())
if n == 1:
  print(0)
  exit()
  
facs = factorization(n)

nums = []

for fac in facs:
  for i in range(1, fac[1]+1):
    nums.append(fac[0]**i)
    
nums = list(set(nums))
cnt = 0
nums.sort()

for num in nums:
  if n % num == 0:
    n = n / num
    cnt += 1
    
print(cnt)
