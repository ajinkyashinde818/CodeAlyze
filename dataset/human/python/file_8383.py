def main():
    K, N = map(int, input().split())
    A = [int(a) for a in input().split()]
    dlist = list()

    for i in range(N):
        if i == N - 1:
            d = A[0] + K - A[-1]
            dlist.append(d)
        else:
            d = abs(A[i] - A[i+1])
            dlist.append(d)
    dlist.sort()
    print(sum(dlist[:N-1]))

if __name__ == "__main__":
    main()
