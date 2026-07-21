from sys import stdin

D = 60
MAX_N = 200005


def input():
    return stdin.readline()[:-1]

def main():
    from builtins import int, map
    N, K = map(int, input().split())
    to = [[None for _ in range(N)] for _ in range(D)]
    to[0] = list(map(lambda x: int(x) - 1, input().split()))
    for i in range(D - 1):
        for j in range(N):
            to[i + 1][j] = to[i][to[i][j]]

    v = 0
    for i in range(D - 1, -1, -1):
        l = 1 << i
        if l <= K:
            v = to[i][v]
            K -= l
    print(v + 1)
    

if __name__ == '__main__':
    main()
