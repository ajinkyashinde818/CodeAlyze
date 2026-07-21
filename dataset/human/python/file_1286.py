import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
x = 0
s = sum(A)
ab = -1
for i in range(n-1):
    a = A[i]
    x += a
    if ab == -1:
        ab = abs(s - 2*x)
    else:
        ab = min(ab, abs(s - 2*x))
print(ab)
