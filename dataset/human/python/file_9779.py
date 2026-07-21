import sys
int1 = lambda x: int(x) - 1
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

N, K = map(int, readline().split())
A = list(map(int1, readline().split()))

visited = [0] * N
order = [0]
visited[0] = 1

pos = 0
while True:
    next_town = A[pos]
    
    if visited[next_town] == 1:
        order.append(next_town)
        break
    visited[next_town] += 1
    pos = next_town
    order.append(pos)

idx = order.index(order[-1])
l_l = len(order) - idx - 1
l = len(order) -1 - l_l

if K < len(order):
    print(order[K] + 1)
    sys.exit()
    
K -= l
K %= l_l

print(order[l+K]+1)
