import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int,input().split()))
ans = 0
res = 0
flag = 0
for i in range(len(A)):
    if A[i]<0:
        res += 1
        A[i] *= -1
    elif A[i] == 0:
        flag = 1
if res%2 == 1 and flag != 1:
    print(sum(A) - min(A)*2)
else:
    print(sum(A))
