def main():
    K, N = (int(i) for i in input().split())
    A = [int(i) for i in input().split()]
    ans = K
    less = max(A[i+1] - A[i] for i in range(N-1))
    less = max(less, A[0] + K - A[-1])
    print(ans - less)


if __name__ == '__main__':
    main()
