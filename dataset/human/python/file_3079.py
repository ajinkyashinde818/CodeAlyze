import collections

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

def main():
    n = int(input())
    c = collections.Counter(prime_factorize(n))
    li = list(c.values())
    ans = 0
    for i in li:
        k = i
        for j in range(60):
            k -= j
            if k < 0:
                ans += j - 1
                break
    print(ans)

 
 
if __name__ == '__main__':
  main()
