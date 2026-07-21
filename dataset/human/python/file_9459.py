import sys
N, K = [int(x) for x in input().split()]
A = [None] + [int(x) for x in input().split()]

visited = [False] * (N + 1)
by = [None] * (N + 1)

visited[1] = True
by[1] = 0 # 0番目のテレポーテーションで到着

i = 1
tel = 0
for tel in range(1, N + 2):
    i = A[i]
    if tel == K:
        print(i)
        sys.exit(0)
    if visited[i]:
        cycle = tel - by[i]
        offset = by[i]
        break
    visited[i] = True
    by[i] = tel

# iからスタートして、M回移動した地点
M = (K - offset) % cycle

for j in range(M):
    i = A[i]

print(i)
