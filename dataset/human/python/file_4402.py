import math
n = int(input())
lis = []
for i in range(2,math.ceil(math.sqrt(n))+1):
    cnt = 0
    while n % i == 0:
        n //= i
        cnt += 1
    if cnt:lis.append(cnt)
if n != 1:
    lis.append(1)
ans = 0

if lis == []:
    if n == 1:
        print(0)
        exit()
    else:
        print(1)
        exit()
for num in lis:
    go = 1
    while num >= go:
        ans += 1
        num -= go
        go += 1
print(ans)
