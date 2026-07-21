def main():
    N = int(input())

    *A, = (int(x) - 1 for x in input().split())
    B = map(int, input().split())
    *C, = map(int, input().split())

    ans = sum(B)
    for a, b in zip(A, A[1:]):
        if b - a == 1:
            ans += C[a]
    print(ans)


if __name__ == '__main__':
    main()
