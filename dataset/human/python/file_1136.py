import sys
input = lambda: sys.stdin.readline().rstrip()
N = int(input())
A = [int(a)-1 for a in input().split()]
B = [int(a)-1 for a in input().split()]

LA = [0] * N + [N]
LB = [0] * N + [N]
j = 0
for i in range(N):
    LA[i] = j
    while j < N and A[j] == i:
        j += 1
j = 0
for i in range(N):
    LB[i] = j
    while j < N and B[j] == i:
        j += 1

NG = [0] * (N + 1)
for l1, r1, l2, r2 in zip(LA[:-1], LA[1:], LB[:-1], LB[1:]):
    ngl = l1-r2+1
    ngr = r1-l2
    if ngl < ngr < 0:
        NG[ngl+N] += 1
        NG[ngr+N] -= 1
    elif ngl < 0 <= ngr:
        NG[ngl+N] += 1
        NG[N] -= 1
        NG[0] += 1
        NG[ngr] -= 1
    elif 0 <= ngl < ngr:
        NG[ngl] += 1
        NG[ngr] -= 1
for i in range(N):
    NG[i+1] += NG[i]

for i in range(N):
    if NG[i]: continue
    print("Yes")
    print(*[a + 1 for a in (B[-i:] + B[:-i] if i else B)])
    break
else:
    print("No")
