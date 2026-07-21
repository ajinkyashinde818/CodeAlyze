def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    ans = 0
    storage = -1
    for i in range(N):
        ans = ans + B[A[i] - 1]
        if storage + 1 == A[i]:
            ans = ans + C[storage - 1] 
        storage = A[i]
    print(ans)
main()
