def main():
    K, N = tuple([int(_x) for _x in input().split()])
    A = [int(_x) for _x in input().split()]
    maxdiff = 0
    for i in range(1, len(A)):
        maxdiff = max(maxdiff, A[i] - A[i-1])
    maxdiff = max(maxdiff, K + A[0] - A[-1])
    print(K-maxdiff)


main()
