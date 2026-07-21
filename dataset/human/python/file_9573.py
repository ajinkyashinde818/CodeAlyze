import sys

n, k = map(int, input().split())
a = list(map(lambda x: int(x)-1, input().split()))

is_visited = [0] * n
visited = list()
i = 0
cnt = 0
while True:
    if cnt == k:
        print(i+1)
        sys.exit()
    if is_visited[i]:
        break
    is_visited[i] = 1
    visited.append(i)
    i = a[i]
    cnt += 1

si = visited.index(i)
loop = visited[si:]
n_loop = len(loop)
left_k = k - cnt
print(loop[left_k % n_loop] + 1)
