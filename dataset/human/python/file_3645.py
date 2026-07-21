from collections import Counter

def prime_factorization(n):
    A = []
    while n % 2 == 0:
        n //= 2
        A.append(2)
    i = 3
    while i * i <= n:
        if n % i == 0:
            n //= i
            A.append(i)
        else:
            i += 2
    if n != 1:
        A.append(n)
    return A


n = int(input())

A = list(Counter(prime_factorization(n)).values())

ans = 0
e = 1
while True:
    cnt = 0
    for i in range(len(A)):
        if A[i] >= e:
            A[i] -= e
            cnt += 1
    if cnt == 0:
        break
    ans += cnt
    e += 1

print(ans)
