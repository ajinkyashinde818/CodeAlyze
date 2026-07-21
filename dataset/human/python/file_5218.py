import sys
sys.setrecursionlimit(200010)
def input():
    return sys.stdin.readline()[:-1]

def main():
    N, M = list(map(int,input().split()))
    G = [set([]) for k in range(N)]
    for i in range(M):
        A, B = set(map(int,input().split()))
        G[A-1].add(B-1)
        G[B-1].add(A-1)
    for e in G[0]:
        if e in G[N-1]:
            print("POSSIBLE")
            exit(0)
    print("IMPOSSIBLE")
if __name__ == '__main__':
    main()
