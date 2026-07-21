def cin():
    in_ = list(map(int,input().split()))
    if len(in_) == 1:  return in_[0]
    else:  return in_

def fact_prime(n, p):
    ret = 0
    temp = p
    while(n >= p):
        ret += n // p
        p *= temp
    return ret

n = cin()

if n % 2:
    n = (n + 1) // 2
    a2 = fact_prime(2 * n, 2)
    a5 = fact_prime(2 * n, 5)
    b2 = fact_prime(n, 2) + n
    b5 = fact_prime(n, 5)
    ans = min(a2 - b2, a5 - b5)
else:
    n = n // 2
    ans = fact_prime(n, 5)
print(ans)
