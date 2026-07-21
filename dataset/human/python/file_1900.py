def main():
    N, M = map(int, input().split())
    A = [input() for _ in range(N)]
    B = [input() for _ in range(M)]
    
    def match(y, x):
        for i in range(M):
            for j in range(M):
                if A[y+i][x+j] != B[i][j]:
                    return False
        return True
    
    if any(match(i, j) for j in range(N-M+1) for i in range(N-M+1)):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
