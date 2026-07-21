from math import sqrt

n = int(input())

if n == 1:
    print(0)
    exit()

n_sqrt = int(sqrt(n))

dp = [-1] * (n_sqrt+2)

for i in range(2, n_sqrt+2):
    if dp[i] == -1:
        dp[i] = 1
        for j in range(i*2, n_sqrt+2, i):
            dp[j] = 0

prime = []

for i in range(2, n_sqrt+2):
    if dp[i] == 1:
        prime.append(i)

prime.append(n)

memo = []
for p in prime:
    cnt = 0
    while n%p==0:
        n //= p
        cnt += 1

    if cnt:
        memo.append(cnt)

if n > 1:
    memo.append(1)

ans = 0

for j in memo:
    k = 1
    while True:

        if k*(k+1)//2 <= j <= k*(k+3)//2:
            ans += k
            break
        k += 1

print(ans)
