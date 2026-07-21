from collections import defaultdict
from math import factorial

n = int(input())

if n == 1:
    print(0)
    exit()


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr


ls = factorization(n)
ans = 0

for i, j in ls:
    cnt = 0
    for i in range(1, 10*10):
        cnt += i
        if cnt > j:
            break
        ans += 1

print(ans)
