def main():
    N, M = map(int, input().split())
    A = []
    for _ in range(N):
        A.append(input())
    B = []
    for _ in range(M):
        B.append(input())
    for i in range(N-M+1):
        for j in range(N-M+1):
            isMatch = True
            for k in range(M):
                for l in range(M):
                    if A[i+k][j+l] != B[k][l]:
                        isMatch = False
                        break
            if isMatch:
                return "Yes"
    return "No" 


if __name__ == '__main__':
    print(main())
