from collections import defaultdict

N = int(input())


def prime_factorization(N):
    PC = defaultdict(int)

    P = 2
    while N % P == 0:
        PC[P] += 1
        N //= P

    P = 3
    while P * P <= N:
        if N % P == 0:
            PC[P] += 1
            N //= P
        else:
            P += 2

    if N != 1:
        PC[N] += 1

    return PC


PC = prime_factorization(N)

ans = 0
for PI in PC.values():
    PIc = 1
    while PI >= PIc:
        ans += 1
        PI -= PIc
        PIc += 1

print(ans)
