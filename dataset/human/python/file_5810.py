import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

x = sum(B)
for a,b in zip(A,A[1:]):
    if b == a+1:
        x += C[a-1]

print(x)
