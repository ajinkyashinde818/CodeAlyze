import sys
def input():
    return sys.stdin.readline()[:-1]

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

cnt = 0
pre = -10
for i in range(N):
    a = A[i] - 1
    cnt += B[a]
    if pre+1 == a:
        cnt += C[pre]
    pre = a
print(cnt)
