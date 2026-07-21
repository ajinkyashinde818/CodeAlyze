import math
def factorization(n):
    fac_list = []
    tmp = n
    for i in range(2, int(math.sqrt(n)) + 1):
        if tmp % i == 0:
            cnt = 0
            while tmp % i == 0:
                cnt += 1
                tmp //= i
            fac_list.append(cnt)
    if tmp != 1:
        fac_list.append(1)
    if fac_list == []:
        fac_list.append(1)
    return fac_list

n = int(input())
fac_list = factorization(n)
ans = 0

for x in fac_list:
    tmp = 1
    while x - tmp >= 0:
        x -= tmp
        tmp += 1
        ans += 1

print(ans if n != 1 else 0)
