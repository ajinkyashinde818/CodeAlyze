N = int(input())
if N == 1:
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


primes = factorization(N)

count = 0
for p in primes:
    c = 0
    t = 0
    for i in range(1, 10 ** 9):
        c += i
        t += 1
        if c > p[1]:
            count += t - 1
            break
        elif c == p[1]:
            count += t
            break

print(count)
