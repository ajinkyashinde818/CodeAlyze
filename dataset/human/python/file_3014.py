from math import sqrt
from bisect import bisect


def main():
    N = int(input())
    factor = {}
    max_count = 1
    while N > 1:
        for i in range(2, int(sqrt(N)) + 1):
            if N % i == 0:
                N = N // i
                if i in factor:
                    factor[i] += 1
                    if max_count < factor[i]:
                        max_count = factor[i]
                else:
                    factor[i] = 1
                break
        else:
            if N in factor:
                factor[N] += 1
                if max_count < factor[N]:
                    max_count = factor[N]
            else:
                factor[N] = 1
            N = 1
    sum_up = [n * (n + 1) // 2 for n in range(max_count + 1)]
    ans = 0
    for prime, count in factor.items():
        ans += bisect(sum_up, count)-1
    print(ans)


if __name__ == "__main__":
    main()
