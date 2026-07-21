import math

n = int(input())

prm_dict = {}
for i in range(2, math.floor(math.sqrt(n))):
    while n % i == 0:
        n //= i
        if i not in prm_dict.keys():
            prm_dict[i] = 0
        prm_dict[i] += 1
    if n == 1:
        break
if n != 1:
    prm_dict[n] = 1

ans = 0
for prm in prm_dict.keys():
    prm_cnt = prm_dict[prm]
    i = 1
    while prm_cnt >= i:
        prm_cnt -= i
        i += 1
        ans += 1

print(ans)
