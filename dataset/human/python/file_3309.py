from collections import defaultdict


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


def main():
    N = int(input())

    if N == 1:
        print(0)
        exit()

    a = prime_factorize(N)

    l = [1, 3, 6, 10, 15, 21, 28, 36, 45]

    dic = defaultdict(int)
    for aa in a:
        dic[aa] += 1

    ans = 0
    for d in dic:
        tmp = dic[d]
        count = 0
        for ll in l:
            if ll > tmp:
                break
            count += 1
        ans += count

    print(ans)


if __name__ == "__main__":
    main()
