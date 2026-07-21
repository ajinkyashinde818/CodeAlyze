import math
N = int(input())
n = N
ans = 0


def is_prime(n):
    if n == 1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True


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


d = set()

for x, a in factorization(N):
    tmp = 1
    if x == 1:
        continue
    for i in range(a):
        tmp *= x
        d.add(tmp)

d = list(d)
d.sort()
for i in d:
    if N % i == 0:
        N = N // i
        ans += 1

print(ans)
