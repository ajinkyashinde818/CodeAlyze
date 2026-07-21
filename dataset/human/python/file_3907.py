import math
import bisect

def main():
    n = int(input())
    primes = {}
    s = [(1+i) * i // 2 for i in range(1, 300000)]
    for i in range(2, int(math.sqrt(n))+2):
        if n % i == 0:
            primes[i] = 0
        else:
            continue
        while n % i == 0:
            n /= i
            primes[i] += 1

    if n != 1:
        primes[n] = 1

    ans = 0
    for _, v in primes.items():
        i = bisect.bisect_right(s, v)
        ans += i

    print(ans)


if __name__ == '__main__':
    main()
