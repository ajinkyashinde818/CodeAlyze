n = int(input())
if n == 1: print(0); exit()

def is_prime(x):
    if x == 2: return True
    if x == 1 or not x % 2: return False
    for i in range(3, int(x**0.5)+1, 2):
        if not x % i: return False
    else: return True
if is_prime(n): print(1); exit()

def get_primes(lim):
    table = [True] * (lim+1)
    table[0:2] = False, False
    for i in range(2, int(lim**0.5)+1):
        if not table[i]: continue
        for j in range(i*2, lim+1, i):
            table[j] = False
    return [i for i in range(lim+1) if table[i]]

def factorize(x, primes):
    res = []
    for p in primes:
        if p ** 2 > x: break
        cnt = 0
        while not x % p:
            x //= p
            cnt += 1
        if cnt: res.append(cnt)
    if x > 1: res.append(1)
    return res

p = get_primes(10**6*2)
f = factorize(n, p)
ans = 0
for x in f:
    for i in range(1, 100):
        if i <= x:
            x -= i
            ans += 1
        else: break

print(ans)
