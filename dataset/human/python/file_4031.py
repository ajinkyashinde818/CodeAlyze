import sys
from bisect import bisect

def solve():
    input = sys.stdin.readline
    N = int(input())
    sum = [0] * 41
    for i in range(1, 41):
        sum[i] = sum[i-1] + i
    count = 0
    k = N
    for i in range(2, N + 1):
        if i ** 2 > k: break
        if k % i == 0:
            d = 0
            while k % i == 0:
                d += 1
                k //= i
            count += bisect(sum, d) - 1
    if k > 1: count += 1
    print(count)

    return 0

if __name__ == "__main__":
    solve()
