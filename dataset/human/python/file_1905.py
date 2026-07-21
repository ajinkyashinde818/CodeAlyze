import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    A = [list(input().rstrip()) for _ in range(N)]
    B = [list(input().rstrip()) for _ in range(M)]
    mv = N - M + 1
    for i in range(mv):
        for j in range(mv):
            sub_A = [r[j:j+M] for r in A[i:i+M]]
            if sub_A == B:
                print("Yes")
                exit()
    print("No")


if __name__ == '__main__':
    main()
