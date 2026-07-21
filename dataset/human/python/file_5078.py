import sys

readline = sys.stdin.buffer.readline
ni = lambda: int(readline().rstrip())
nm = lambda: map(int, readline().split())
nl = lambda: list(map(int, readline().split()))

def solve():
    n, m = nm()
    G = [list() for _ in range(n)]
    for _ in range(m):
        u, v = nm()
        u -= 1; v -= 1
        G[u].append(v)
        G[v].append(u)
    if (set(G[0]) & set(G[n-1])):
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')
    return

solve()

# T = ni()
# for _ in range(T):
#     solve()
