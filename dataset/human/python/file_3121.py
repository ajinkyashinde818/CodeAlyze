from collections import defaultdict

n = int(input())
dd = defaultdict(int)
for i in range(2, int(n ** (1 / 2) + 2)):
    while n % i == 0:
        dd[i] += 1
        n //= i
if n != 1:
    dd[n] += 1
ans = 0
cnt = {}
for i in range(20):
    tmp = i * (i + 1) // 2
    cnt[tmp] = i
for i, j in dd.items():
    for num in cnt:
        if j >= num:
            continue
        ans += cnt[num] - 1
        break
print(ans)
