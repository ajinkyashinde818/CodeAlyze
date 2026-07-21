def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    prev = -1
    ans = 0
    for i in range(N):
        ans += B[i]
        if prev == A[i]-1:
            ans += C[prev-1]
        prev = A[i]
    print(ans)


if __name__ == "__main__":
    main()
