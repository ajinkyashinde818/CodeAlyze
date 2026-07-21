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
    A, B = map(int, input().split())
    XA = prime_factorize(A)
    XB = prime_factorize(B)
    sum = 1
    for i in XA:
        if i in XB:
            XB.remove(i)
        sum *= i

    for j in XB:
        sum *= j

    print(sum)

main()
