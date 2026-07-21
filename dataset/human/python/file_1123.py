import sys
input = sys.stdin.readline

N=int(input())
A=tuple(map(int,input().split()))
B=tuple(map(int,input().split()))
sum = [0]*N

for i in range(N):
    sum[A[i]-1] += 1
    sum[B[i]-1] += 1

if max(sum) > N:
    print('No')
    exit()

print('Yes')
for i in range(N):
    hit = False
    for j in range(N):
        a = A[j]
        b = B[(j + i) % N]
        if a == b:
            hit = True
            break
    if not hit:
        ans = []
        for j in range(N):
            ans.append(str(B[(j+i) % N]))
        print(" ".join(ans))
        exit()
