import sys
input = sys.stdin.readline

n, k = (int(x) for x in input().split())
seq = [int(x) for x in input().split()]
visited = [[False,0] for _ in xrange(n)]

t = 1
cnt = 0
if n < k:
    while not visited[t-1][0]:
        visited[t-1][0] = True
        visited[t-1][1] = cnt
        t = seq[t-1]
        cnt += 1

    cycle_len = cnt - visited[t-1][1]
else:
    cycle_len = n
for _ in xrange((k-visited[t-1][1]) % cycle_len):
    t = seq[t-1]
print(t)
