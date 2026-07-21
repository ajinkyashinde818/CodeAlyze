N, M = [int(x) for x in input().split()]
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]


def f(r, c):
    if r+M > N or c+M > N:
        return False
    for i in range(M):
        if A[r+i][c:c+M] != B[i]:
            return False
    return True


def main():
    for i in range(N):
        for j in range(N):
            if f(i,j):
                print("Yes")
                return 
    print("No")

main()
