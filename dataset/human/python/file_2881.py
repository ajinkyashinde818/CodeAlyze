import math

n = int(input())
if n == 1:
    print(0)
    exit(0)
max = int(math.sqrt(n) + 0.1)
ans = 0
for i in range(2, max):
    count = 0
    while n % i == 0:
        count += 1
        n = n // i
    if count > 0:
        for j in range(1, 64):
            if count >= j:
                ans += 1
            else:
                break
            count -= j
    if n == 1:
        print(ans)
        exit(0)
print(ans + 1)
