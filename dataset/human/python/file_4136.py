def get_prime_factorizations(n):
    """
    [summary]

    Parameters
    ----------
    n : int
        the number factorized by prime numbers.

    Returns
    -------
    dict[int: int]
        prime and exponent pair
        ex.) if n == 40, the function return  {2:3, 5:1} 
    """    
    root_n = int( n**(1/2) )
    primes = {2:0}
    primes.update({i:0 for i in range(3, root_n+1, 2)})
    for i in primes.keys():
        if n == 1:
            primes = {i: v for i, v in primes.items() if v > 0}
            return primes
        # count exponent
        exponent = 0
        while n % i == 0:
            n //= i
            exponent += 1
        # store the prime and exponent
        primes[i] = exponent

    primes = {i: v for i, v in primes.items() if v > 0}

    if n!=1:
        primes[n] = 1

    if len(primes) == 0:
        return {n: 1}
    return primes

n = int(input())
if n == 1:
    print(0)
else:
    primes =  get_prime_factorizations(n)
    result = 0
    for exponent  in primes.values():
        count = 0
        while exponent - count > 0:
            count += 1
            exponent -= count
        result += count
    print(result)
