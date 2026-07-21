import sys
sys.setrecursionlimit(1000000000)
ii = lambda: int(input())
mis = lambda: map(int, input().split())
lmis = lambda: list(mis())

def main():
    N = ii()
    A, B, C = lmis(), lmis(), lmis()
    ans = B[A[0]-1]
    for i in range(1, N):
        a = A[i]-1
        ans += B[a]
        if A[i]-A[i-1]==1:
            ans += C[a-1]
    
    print(ans)

main()
