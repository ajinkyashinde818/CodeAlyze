import math


def is_prime(n):
    if n == 1:
        return False

    for k in range(2, int(math.sqrt(n)) + 1):
        if n % k == 0:
            return False

    return True


def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)
    divisors.sort()
    return divisors


N = int(input())
divisors = make_divisors(N)

cnt = 0
for d in divisors:
    if d == 1:
        continue

    if N < d:
        break

    if is_prime(d):
        dd = d
        while True:
            if N < dd:
                break
            if N % dd == 0:
                N //= dd
                cnt += 1
                dd *= d
            else:
                break
print(cnt)
