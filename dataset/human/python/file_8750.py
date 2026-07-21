def solve():
    K, N = list(map(int, input().split()))
    A = list(map(int, input().split()))
    A.sort()

    max_dist = 0
    for i in range(1, N):
        dist_tmp = A[i] - A[i-1]
        if(dist_tmp > max_dist):
            max_dist = dist_tmp
    dist_over_zero = K - (A[N-1] - A[0])
    if(dist_over_zero > max_dist):
        ans = K - dist_over_zero
    else:
        ans = K - max_dist
    print(ans)


if __name__ == "__main__":
    solve()
