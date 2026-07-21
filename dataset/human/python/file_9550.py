import sys
input = sys.stdin.readline

n, k = map(int,input().split())
A = list(map(int,input().split()))

for i in range(n):
    A[i] -= 1

B = [0]
F = [-1] * n
F[0] = 0
s = A[0]
i = 0
while F[s] == -1:
    i += 1
    B.append(s)
    F[s] = i
    s = A[s]

# print(F[s], i+1)

if k <= F[s]:
    print(B[k] + 1)
else:
    ind = (k-F[s]) % (i+1-F[s]) + F[s]
    print(B[ind] + 1)
