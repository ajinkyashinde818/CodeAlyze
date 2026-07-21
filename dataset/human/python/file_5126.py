import sys
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7



def main():
    N, M = map(int, readline().split())
    path = [[] for _ in range(N+1)]
    for _ in range(M):
        a,b = map(int, readline().split())
        path[a].append(b)
        path[b].append(a)
    if set(path[1])&set(path[N]):
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')

if __name__ == '__main__':
    main()
