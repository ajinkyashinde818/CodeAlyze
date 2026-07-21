import statistics
import math

MOD = 10**9+7


def main():
    n = int(input())
    x = list(map(int, input().split()))

    c = 0
    t = 0
    for i in range(n-1):
        c += pow(i+1, MOD-2, MOD)
        t += c * (x[i+1]-x[i])
        t %= MOD

    fact = math.factorial(n-1) % MOD
    print(t * fact % MOD)


main()
