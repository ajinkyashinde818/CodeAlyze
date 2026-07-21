import collections
n, m = map(int, input().split())
c = 0
B = []
C = []
for i in range(m):
    a, b = map(int, input().split())
    if a == 1:
        B.append(b)
    elif b == n:
        B.append(a)
C = collections.Counter(B)
for i in C:
    if C[i] > 1:
        print("POSSIBLE")
        exit()
print("IMPOSSIBLE")
