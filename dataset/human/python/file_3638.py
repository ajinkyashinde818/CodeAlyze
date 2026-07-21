import sys

n = int(input())
ans = 0
if n == 1:
    print(0)
    sys.exit()
ma = int(n**(0.5))+1
for i in range(2,ma):
    j = 1
    k = 0
    while n%i == 0:
        k += 1
        n //= i
    else:
        while j <=k:
            ans += 1
            k -= j
            j += 1
if n != 1:
    ans += 1
print(ans)
