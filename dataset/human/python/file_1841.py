def judge(A,B,n,m):
    C = []
    for i in range(n-m+1):
        for j in range(n-m+1):
            C = [A[i+k][j:m+j] for k in range(m)]
            if B == C:
                return True
    return False

def main():
    N,M = map(int,input().split())
    A = [input() for _ in range(N)]
    B = [input() for _ in range(M)]

    if judge(A,B,N,M):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
