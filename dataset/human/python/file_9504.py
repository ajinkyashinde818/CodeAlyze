from collections import deque
N, K = map(int, input().split())

A = list(map(int, input().split()))

loop = deque([0])
teleported = [False] * N

loop_start = 0
loop_end = []

while True:
    i = loop[len(loop) - 1]
    if teleported[i]:
        loop_end = [i, A[i] - 1]        
        break
    teleported[i] = True
    loop.append(A[i] - 1)

cnt = [0] * (N)

for i in range(len(loop)):
    cnt[loop[i]] += 1
    if cnt[loop[i]] == 2:
        loop_end[0] = i
        cnt[0] = loop[i]

loop_start = loop.index(cnt[0])
loop_end = loop_end[0]
loop = list(loop)
loop_2 = loop[loop_start:loop_end]

if K < loop_start:
    print(loop[K] + 1)

else:
    ans = loop_2[(K - loop_start) % len(loop_2)] + 1
    print(ans)
