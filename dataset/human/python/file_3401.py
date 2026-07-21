import math


def prime_factors(n):
    count = {2: 0}

    while n % 2 == 0:
        n = n / 2
        count[2] += 1

    for i in range(3, int(math.sqrt(n))+1, 2):
        count[i] = 0
        while n % i == 0:
            n = n / i
            count[i] += 1

    if n > 2:
        if int(n) in count:
            count[int(n)] += 1
        else:
            count[int(n)] = 1
    # print(count)
    ans = 0
    for k in count.values():
        if k:
            j = int((2*k)**0.5)
            while j*(j+1) <= 2*k:
                j += 1
            ans += j-1

    return ans


n = int(input())

print(prime_factors(n))
