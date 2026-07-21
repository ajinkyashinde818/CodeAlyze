from collections import defaultdict


def main():
    N = int(input())
    i = 2
    primes = defaultdict(int)
    while i**2 <= N:
        while N % i == 0:
            primes[i] += 1
            N //= i
        i += 1
    if N > 1:
        primes[N] = 1
    elements = list(primes.values())
    ans = 0
    for i in range(len(elements)):
        for j in range(1, 10):
            if elements[i] >= j:
                elements[i] -= j
                ans += 1
    print(ans)


if __name__ == "__main__":
    main()
