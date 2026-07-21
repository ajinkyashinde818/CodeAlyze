import sys
from bisect import bisect_right
n = int(input())
data = [n*(n+1)//2 for n in range(1,40)]
cnt2 = 0
while n % 2 == 0:
    cnt2 += 1
    n //= 2
ans = bisect_right(data,cnt2)
if n == 1:
    print(ans)
    sys.exit()
for i in range(3,int(n**(0.5))+1,2):
    cnt = 0
    while n % i == 0:
        cnt += 1
        n //= i
    ans += bisect_right(data,cnt)
    if n == 1:
        break
else:
    ans += 1
print(ans)
