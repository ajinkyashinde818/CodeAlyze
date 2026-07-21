def get_prime_factorized(N):
    result    = []
    base, exp = 2, 0
    while base ** 2 <= N:
        while N % base == 0:
            N    = N // base
            exp += 1
        if exp > 0:
            result.append([base, exp])
        base, exp = base + 1, 0
    if N > 1:
        result.append([N, 1])
    return result


N = int(input())

L = get_prime_factorized(N)
R = 0

for p, e in L:
    sum = 1
    num = 1
    while True:
        if e >= sum + num + 1:
            num += 1
            sum += num
        else:
            break
    R += num

print(R)
