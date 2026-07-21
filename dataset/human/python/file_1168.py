from collections import deque

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))


cnt_a = [0 for i in range(N+1)]
cnt_b = [0 for i in range(N+1)]

for a in A:
    cnt_a[a]+=1
for b in B:
    cnt_b[b]+=1

for i in range(N+1):
    if cnt_a[i]+cnt_b[i]>N:
        exit(print("No"))

print("Yes")

aidx = [i for i in range(N)]
bidx = [N-i-1 for i in range(N)]
bidx_left = deque([])

res = [-1 for i in range(N)]

while aidx and bidx:
    if A[aidx[-1]]!=B[bidx[-1]]:
        res[bidx[-1]] = aidx[-1]
        bidx.pop()
        aidx.pop()
    elif bidx_left and B[bidx_left[0]]!=A[aidx[-1]]:
        res[bidx_left[0]] = aidx[-1]
        bidx_left.popleft()
        aidx.pop()
    else:
        bidx_left.append(bidx[-1])
        bidx.pop()

while aidx:
    if A[aidx[-1]]!=B[bidx_left[-1]]:
        res[bidx_left[-1]] = aidx[-1]
        bidx_left.pop()
        aidx.pop()
    else:
        break

aidx = aidx[::-1]
while aidx:
    if A[aidx[-1]]!=B[bidx_left[-1]]:
        res[bidx_left[-1]] = aidx[-1]
        bidx_left.pop()
        aidx.pop()
    else:
        break

if aidx:
    c = len(aidx)
    num = A[aidx[-1]]
    change = []
    for i in range(N):
        if not aidx:
            break
        if res[i]!=-1 and B[i]!=num and A[res[i]]!=num:
            res[bidx_left[-1]] = res[i]
            res[i] = aidx.pop()
            bidx_left.pop()

ans = [0 for i in range(N)]
for i in range(N):
    ans[res[i]]=B[i]

print(*ans)
