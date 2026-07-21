import sys
input = sys.stdin.readline

def get_sieve_of_eratosthenes_new(n):
    import math
    prime = []
    limit = math.sqrt(n)
    data = [i + 1 for i in range(1, n)]
    while True:
        p = data[0]
        if limit <= p:
            return prime + data
        prime.append(p)
        data = [e for e in data if e % p != 0]

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

def get_count(beki) :
    count = 0
    for i in range(1,beki+1) :
        tmp = beki - i
        if (0 <= tmp) :
            count += 1
            beki = tmp
        else :
            return count
    
    return 1

def main() :
    N = int(input())
    count = 0
    if (N == 1) :
        print(0)
        return

    factorized = factorization(N)
    # print(factorized)
    for fact in factorized :
        fact_c = fact[1]
        count += get_count(fact_c)


    # primes = get_sieve_of_eratosthenes_new(N)
    # for prime in primes :
    #     if (N < prime) :
    #         # 判定する素数よりもNが小さければ今後割り切れることはない
    #         break
        
    #     beki = 1
    #     while (True) :
    #         z = prime
    #         if (beki > 1) :
    #             z = pow(prime,beki)
    #         if (N % z == 0) :
    #             count += 1
    #             N = N // z
    #             beki += 1
    #             if (N < prime) :
                    
    #                 break
    #         else :
    #             # わりきれなくなったら終了
    #             break

    print(count)
main()
