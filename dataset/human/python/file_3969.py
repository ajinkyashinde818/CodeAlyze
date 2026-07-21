from collections import Counter

def get_prime_factors(x):
    out = []
    if x < 1:
        return out
    while not x%2:
        out.append(2)
        x //= 2
    i = 3
    while i*i <= x:
        if not x%i:
            out.append(i)
            x //= i
        else:
            i += 2
    if x != 1:
        out.append(x)
    return out
    
def main():
    n = int(input())
    primes = Counter(get_prime_factors(n))
    ans = 0
    for k, v in primes.items():
        num = 1
        while v >= num:
            v -= num
            ans += 1
            num += 1
    print(ans)
    

if __name__ == "__main__":
    main()
