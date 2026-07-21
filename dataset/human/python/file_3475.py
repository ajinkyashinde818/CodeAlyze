import collections

def prime_factorize(n):
    a = []
    while n%2 == 0:
        a.append(2)
        n //=  2
    f = 3
    while f*f <= n :
        if n % f ==0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


if __name__=="__main__":
    N = int(input())
    count = 0
    counter = collections.Counter(prime_factorize(N))
    output = 0
    for prime in counter:
        num_prime = 1
        count = 1
        while True:
            if counter[prime] >= num_prime:
                output += 1
                count += 1
                num_prime += count
            else:
                break
    print(output)
