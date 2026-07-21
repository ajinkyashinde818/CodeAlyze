def main():

    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    ans = K
    dist = []
    for i in range(N-1):
        dist.append(A[i+1] - A[i])
    dist.append(A[0]+K - A[N-1])

    for v in dist:
        ans = min(ans, K - v)
    return ans


if __name__ == '__main__':
    print(main())
