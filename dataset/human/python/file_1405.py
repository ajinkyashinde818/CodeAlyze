def main():
    N = int(input())
    A = list(map(int, input().split()))
    R = [A[0]]
    for i in range(1, N):
        R.append(R[-1]+A[i])
    ans = 2*(10**9)
    for i in range(N-1):
        x = R[i]
        y = R[N-1] - R[i]
        ans = min(ans, abs(x-y))
    print(ans)


if __name__ == "__main__":
    main()
