import sys

def solve():
    input = sys.stdin.readline
    N, K = map(int, input().split())
    A = [int(a) - 1 for a in input().split()]
    Dist = [-1] * N
    Dist[0] = 0
    now = 0
    for i in range(min(N, K)):
        nextN = A[now]
        if Dist[nextN] == -1:
            Dist[nextN] = i + 1
            now = nextN
        else:
            Left = K - i - 1
            mod = Left % (i + 1 - Dist[nextN])
            snow = nextN
            for j in range(mod):
                snow = A[snow]
            print(snow + 1)
            break
    else:
        for i, d in enumerate(Dist):
            if d == K: 
                print(i + 1)
                break
    return  0

if __name__ == "__main__":
    solve()
