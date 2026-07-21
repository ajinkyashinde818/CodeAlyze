import collections

def trial_division(n):
    if n < 2:
        return []
    
    prime_factors = []

    for i in range(2, int(n**0.5)+1):
        while n % i == 0:
            prime_factors.append(i)
            n //= i
    
    if n > 1:
        prime_factors.append(n)
    
    return prime_factors

counter = 0
if __name__ == "__main__":
    N = int(input())
    
    c = collections.Counter(trial_division(N))
    for primary_number, count in c.items():
        for i in range(1, count+1):            
            z = primary_number ** i
            if N % z == 0:
                counter += 1
                N //= z
    
    print(counter)
