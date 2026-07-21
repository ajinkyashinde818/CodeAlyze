import sys
readline = sys.stdin.readline

N, K = map(int, readline().split())
A = [a - 1 for a in map(int, readline().split())]

count = 0
a = 0
visited = {0:0}
while True:
    count += 1
    K -= 1
    a = A[a]
    if K == 0:
        print(a + 1)
        exit(0)
    if a in visited:
        T = count - visited[a]
        K = K % T
        break
    else:
        visited[a] = count

for i in range(K):
    a = A[a]

print(a + 1)
