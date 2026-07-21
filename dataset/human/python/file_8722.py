import string
def num():
    return int(input())
def nums():
    return list(map(int,input().split()))

K,N = nums()
A = nums()

ans = K*2

for i in range(N):
    start = A[i]
    goal = A[i-1]
    if goal < start:
        goal = K + goal
    dis = goal - start
    if dis < ans:
        ans = dis


print(ans)
