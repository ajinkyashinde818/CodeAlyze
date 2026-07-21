import sys
import collections

def main():

    input = sys.stdin.readline

    N = int(input())

    c = collections.Counter(prime_factorize(N))

    ans = 0

    for value in c.values():
        j = 1
        for i in range(2,1000000):
            j += i

            if value < j:
                ans += (i - 1)
                break


    print(ans)

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

if __name__ == "__main__":
    main()
