import math

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

result = 0
factList = factorization(n)
for fact in factList:
  count = math.floor(math.sqrt(2 * fact[1] + 0.25) - 0.5)
  result += count
print(result)
