from collections import Counter

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

def support(n):
    counter = 0
    temp = 1
    while n - temp >= 0:
        n -= temp
        temp += 1
        counter += 1
    return counter

def main():
    n = int(input())
    factors_counter = Counter(prime_factorize(n))
    answer = 0
    for factor in factors_counter.keys():
        factor_count =factors_counter[factor]
        answer += support(factor_count)
    print(answer)





if __name__ == '__main__':
    main()
