import sys
input=sys.stdin.readline

def main():
    N,M = map(int, input().split())
    A = []
    for _ in range(M):
        A.append(list(map(int, input().split())))
    p1 = [0]*N
    for a in A:
        if a[0] == 1:
            p1[a[1]] = 1
    for a in A:
        if a[1] == N and p1[a[0]]:
            print("POSSIBLE")
            return
    print("IMPOSSIBLE")

if __name__ == '__main__':
    main()
