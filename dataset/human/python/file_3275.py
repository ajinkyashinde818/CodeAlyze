def prime_factorization(n):
    """do prime factorization using trial division

    Returns:
        [[prime1,numbers1],[prime2,numbers2],...]
    """
    res = []
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            cnt=0
            while n%i==0:
                cnt+=1
                n//=i
            res.append([i,cnt])
    if n!=1:
        res.append([n,1])
    return res

def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    prime_factors = prime_factorization(N)
    ans = 0
    for p in prime_factors:
        i = 1
        while i <= p[1]:
            ans += 1
            N /= p[0]**i
            p[1] -= i
            i += 1
    print(ans)

if __name__ == '__main__':
    main()
