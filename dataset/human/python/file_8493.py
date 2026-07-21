def main():
    K,N = (int(i) for i in input().split())
    A = [int(i) for i in input().split()]

    d = []
    n = len(A)
    for i, a in enumerate(A):
        if i == 0:
            d.append(min(A[0] + K - A[1], A[n-1] - A[0]))
        elif i == n-1:
            d.append(min(A[n-1]-A[0], K-A[n-1]+A[N-2]))
        else:
            d.append(min(K-A[i]+A[i-1], A[i]+K-A[i+1]))

    print(min(d))


if __name__ == '__main__':
    main()
