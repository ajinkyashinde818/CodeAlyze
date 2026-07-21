import sys
n = int(sys.stdin.readline())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

score = 0
tmp =-100
for a in A:
    score+=B[a-1]
    if tmp +1 ==a:
        score+=C[tmp-1]
    tmp = a

print(score)
