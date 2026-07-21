def main():
    N = int(input())
    A = [int(x) - 1 for x in input().split()]
    B = [int(x) for x in input().split()]
    C = [int(x) for x in input().split()]
    ans = B[A[0]]
    for n in range(1, N):
        ans += B[A[n]]
        if A[n] - A[n-1] == 1:
            ans += C[A[n-1]]
    print (ans)

if __name__ == "__main__":
    main()
