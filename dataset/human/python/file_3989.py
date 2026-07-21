import sys
import math


def is_prime(N):
    if N == 1:
        return False
    i = 2
    while i * i <= N:
        if N % i == 0:
            return False
        i += 1
    return True

def prime(N):
    prime = []
    is_prime = []  # 全て素数であると初期化
    for i in range(N):
        if i * i > N:
            break
        is_prime.append(True)
    is_prime[0] = is_prime[1] = False # 0,1は素数ではない
    n = len(is_prime)
    for i in range(2, n):
        if is_prime[i]:
            # iは素数である
            prime.append(i)
            for j in range(2 * i, n, i):
                # iの倍数は素数でない
                is_prime[j] = False
    # N以下の素数を表示
    return prime, n

def main():
    N = int(input())
    if N == 1:
        print(0)
    else:
        if is_prime(N):
            print(1)
        else:
            prime_list, n = prime(N)
            used = []
            prime_exponentiation = []
            count = 0
            for i in range(len(prime_list)):
                now = prime_list[i]
                j = 1
                while now ** j <= N:
                    prime_exponentiation.append(now ** j)
                    j += 1
            prime_exponentiation.sort()
            for i in range(len(prime_exponentiation)):
                now = prime_exponentiation[i]
                if N < now:
                    j = 0
                    while not is_prime(N):
                        if N == 1:
                            break
                        while N % prime_list[j] == 0:
                            N //= prime_list[j]
                        j += 1 
                    break
                if N % now == 0:
                    count += 1
                    used.append(now)
                    N //= now
            if N not in used and N != 1:
                count += 1
            print(count)


if __name__ == '__main__':
    main()
