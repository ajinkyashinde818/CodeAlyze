import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int,input().split()))
cnt = 0
for i,a in enumerate(A):
    if a<0:
        cnt += 1
        A[i] = -1*a
A = sorted(A)
print(sum(A)-2*A[0]*(cnt%2))
