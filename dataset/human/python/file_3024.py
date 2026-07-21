import math
n = int(input())
if n == 1:
  print(0)
  exit()

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

ans = 0
for i in arr:
  if i[1] == 1 or i[1] == 2:
    ans += 1
  else:
    ans = ans + int(-1/2 + math.sqrt(1+8*i[1])/2)
print(ans)
