import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))

ANS=sum(B)
for i in range(1,N):
    if A[i-1]==A[i]-1:
        ANS+=C[A[i-1]-1]

print(ANS)
