import copy

n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))

bef = -1
ans = 0
for i in A:
    ans += B[i-1]
    if(bef + 1 == i):
        ans += C[i-2]
    bef = i
print(ans)
