import sys
input = sys.stdin.readline


def main():
    N, M = map(int, input().split())
    A = []
    B = []
    for _ in range(N):
        A.append(input().strip())
    for _ in range(M):
        B.append(input().strip())

    for ay in range(0, N-M+1):
        for ax in range(0, N-M+1):
            m = 0
            for by in range(M):
                for bx in range(M):
                    if A[ay + by][ax + bx] == B[by][bx]:
                        m += 1
                        if m == M*M:
                            print("Yes")
                            return
    print("No")


if __name__ == '__main__':
    main()
