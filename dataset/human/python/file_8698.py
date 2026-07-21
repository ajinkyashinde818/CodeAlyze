def main():
    K, N = map(int, input().split())
    A = list(map(int,input().split()))
    ans = K
    for i in range(0,N,1):
        s = A[i]
        if i == 0:
            g = A[N-1]
            ans = min(ans, g-s)
        else:
            g = A[i-1]
            ans = min(ans, K-(s-g))

    print(ans)

main()
