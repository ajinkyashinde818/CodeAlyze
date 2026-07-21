from sys import stdin
from math import sqrt


def is_prime(q, primes):
    if len(primes) == 0:
        return True

    maxq = int(sqrt(q))
    for prime in primes:
        if prime > maxq:
            break
        if q % prime == 0:
            return False
    return True

def get_primes(n):
    if n < 2:
        return []
    if n == 2:
        return [2]

    max = int(sqrt(n))
    primes = [2]
    for q in range(3, max+1):
        if is_prime(q, primes):
            primes.append(q)

    return primes

def breakdown_to_primes_as_dic(n, primes):
    prime_dic = {}
    for prime in primes:
        if n % prime != 0:
            continue
        prime_dic[prime] = 0
        while n % prime == 0:
            prime_dic[prime] += 1
            n = n // prime
    if n >= 2:
        prime_dic[n] = 1
    return prime_dic

def get_int_sums(n):
    int_sums = [0]
    for i in range(1, n+1):
        int_sums.append(int_sums[i-1] + i)
    int_sums.pop(0)
    return int_sums


def main():
    for line in stdin:
        n = int(line)
        break

    primes = get_primes(n)
    prime_dic = breakdown_to_primes_as_dic(n, primes)

    if len(prime_dic.keys()) == 0:
        print(0)
        return

    max_prime_occurance = max(prime_dic.values())
    int_sums = get_int_sums(max_prime_occurance + 1)

    answer = 0
    for prime in prime_dic.keys():
        occr = prime_dic[prime]
        for i in range(1, len(int_sums)):
            if occr >= int_sums[i-1] and occr < int_sums[i]:
                answer += i
                break

    print(answer)


main()
