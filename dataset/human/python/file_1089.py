from collections import Counter

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

AC = Counter(A)
BC = Counter(B)
if N < max((AC + BC).values()):
    print('No')
    exit()

curA = 0
curB = 0
while curA < N:
    a = A[curA]
    if a == B[curA]:
        while a == B[curB] or A[curB] == B[curA]:
            curB += 1
            curB %= N
        B[curA], B[curB] = B[curB], B[curA]
    curA += 1

print('Yes')
print(*B)
