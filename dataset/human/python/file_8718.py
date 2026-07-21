def solve():
    K,N = [int(i) for i in input().split()]
    A = [int(i) for i in input().split()]
    ans = max_delta = 0
    for i in range(N):
        if i == N-1:
            delta = K - A[i] + A[0]
        else:
            delta = A[i+1] - A[i]
        ans += delta
        max_delta = max(delta, max_delta)
    else:
        ans -= max_delta
    print(ans)

if __name__ == "__main__":
    solve()
