def calc(i, k):
    for _ in range(k):
        i = A[i]
    return i

N, K = map(int, input().split())
M = 3 * 10 ** 5
A = [int(a) - 1 for a in input().split()]

if K < 10 ** 6:
    print(calc(0, K) + 1)
    exit()
i = calc(0, M)
j = A[i]
c = 1
while j != i:
    j = A[j]
    c += 1
r = c
while (K - c - M) % r:
    j = A[j]
    c += 1
print(j + 1)
