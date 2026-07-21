def B_Buffet():
    N = int(input())
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    C = list(map(int,input().split()))
    ans = 0
    for i in range(N):
        ans += B[A[i] - 1]
        if (0 < i) and (A[i] == A[i-1] +1):
            ans += C[A[i-1]-1]
    print(ans)
    
if __name__ == "__main__":
    B_Buffet()
