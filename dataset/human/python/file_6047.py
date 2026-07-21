import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = 0
for i in range(N):
    dinner = A[i] - 1
    ans += B[dinner]
    if i != N-1:
        if dinner + 1 == A[i+1] - 1:
            ans += C[dinner]

print(ans)
