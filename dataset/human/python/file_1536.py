from sys import stdin
input = stdin.readline

N, M = map(int, input().split())
A = [list(input().rstrip()) for _ in range(N)]
B = [list(input().rstrip()) for _ in range(M)]


for i in range(N - M + 1):
    for j in range(N - M + 1):
        br = False
        for k in range(M):
            for l in range(M):
                if A[i + k][j + l] != B[k][l]:
                    br = True
                    break
            if br:
                break
        if not br:
            print("Yes")
            exit()


print("No")
