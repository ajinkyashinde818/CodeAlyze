def factorization(n):
    if n == 1:
        return []
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

def main():
    n = int(input())
    primes = factorization(n)
    count = 0
    for prime in primes:
        e = prime[1]
        k = 1
        while e >= 0:
            e -= k
            k += 1
            if e >= 0:
                count += 1
    print(count)

if __name__ == '__main__':
    main()
