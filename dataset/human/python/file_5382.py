import sys
input = sys.stdin.readline
def main():
    N,M = map(int,input().split())
    root = [[] for _ in range(N)]
    for _ in range(M):
        a,b = map(int,input().split())
        root[a-1].append(b-1)
        root[b-1].append(a-1)
    for i in root[0]:
        if N-1 in root[i]:
            print("POSSIBLE")
            exit()
    print("IMPOSSIBLE")

if __name__ == "__main__":
    main()
