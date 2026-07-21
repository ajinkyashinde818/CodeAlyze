def main():
    N = int(input())
    A = list(map(int, input().split()))
    ans = 0
    cnt = 0
    minimum = float("inf")
    for i in range(N):
        ans += abs(A[i])
        minimum = min(minimum, abs(A[i]))
        if A[i] < 0:
            cnt += 1
    if cnt % 2 == 1:
        ans -= minimum * 2
    print(ans)


if __name__ == "__main__":
    main()
