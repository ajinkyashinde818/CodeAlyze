from collections import deque, Counter
def prime_factorize(n):
    a = deque([])
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

N = int(input())
A = Counter(prime_factorize(N))
B = [1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66]
ans = 0
for i in A:
    for j in range(len(B)):
        if B[j] <= A[i] < B[j + 1]:
            ans += (j + 1)
            break
print(ans)
