def main():
    from sys import setrecursionlimit, stdin
    from os import environ
    from collections import defaultdict, deque, Counter
    from math import ceil, floor, gcd
    from itertools import accumulate, combinations, combinations_with_replacement
    setrecursionlimit(10**6)
    dbg = (lambda *something: print(*something)) if 'TERM_PROGRAM' in environ else lambda *x: 0
    input = lambda: stdin.readline().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    P = 10**9+7
    INF = 10**9+10

    def sieve_of_eratosthenes(upper_bound):
        upper_bound += 1
        P = [True] * upper_bound
        P[0] = P[1] = False
        for i in range(4,upper_bound,2):
            P[i] = False
        for i in range(3,int(upper_bound**0.5),2):
            if P[i]:
                for j in range(i**2,upper_bound,i):
                    P[j] = False
        res = []
        for i in range(upper_bound):
            if P[i]:
                res.append(i)
        return res






    N = II()
    primes = deque()
    p_counts = deque()
    tmp = N
    if tmp % 2 == 0:
        c = 0
        while tmp % 2 == 0:
            tmp //= 2
            c += 1
        primes.append(2)
        p_counts.append(c)
        
    for i in range(3,int(N**0.5)+1,2):
        c = 0
        if tmp % i == 0:
            while tmp % i == 0:
                tmp //= i
                c += 1
            primes.append(i)
            p_counts.append(c)

    if tmp != 1:
        primes.append(tmp)
        p_counts.append(1)



    ans = 0



    for i in p_counts:
        max_num = 1
        while (1+max_num)*max_num//2 <= i:
            max_num += 1

        ans += max_num-1
    print(ans)
            



    
main()
