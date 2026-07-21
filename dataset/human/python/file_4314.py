N = int(input())

def factorization_in_prime_number(x):
    prime_factor = []
    degree = 0
    while x % 2 == 0:
        x //= 2
        degree += 1
    if degree:
        prime_factor.append((2, degree))
    m = int(x**.5) + 1
    for i in range(3, m, 2):
        degree = 0
        while x % i == 0:
            x //= i
            degree += 1
        if degree:
            prime_factor.append((i, degree))
    if x != 1:
        prime_factor.append((x, 1))
    return prime_factor


z = factorization_in_prime_number(N)
ans = 0
for x, i in z:
    cnt = 0
    while cnt*(1+cnt)/2 < i:
        cnt += 1
    if cnt*(1+cnt)/2 > i:
        cnt -= 1
    # print(cnt, i)
    ans += cnt
print(ans)
