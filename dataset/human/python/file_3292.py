from collections import Counter


def main():
    n = int(input())
    m = n
    factorization_p = []
    while m % 2 == 0:
        factorization_p.append(2)
        m //= 2
    prime_num = 3
    while prime_num * prime_num <= m:
        if m % prime_num == 0:
            factorization_p.append(prime_num)
            m //= prime_num
        else:
            prime_num += 2
    if m != 1:
        factorization_p.append(m)
    factorization_p = Counter(factorization_p)
    answer = 0
    for _, p in factorization_p.items():
        i = 1
        p *= 2
        while i * (i + 1) <= p:
            answer += 1
            i += 1
    print(answer)


if __name__ == '__main__':
    main()
