def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))

    shiftA = A[1:] + [K+A[0]]

    subA = [shiftA[i] - A[i] for i in range(N)]
    maxA = max(subA)
    subA.remove(maxA)

    print(sum(subA))

if __name__ == '__main__':
    main()
