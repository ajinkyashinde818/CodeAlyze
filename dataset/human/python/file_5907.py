def main() -> None:
    N = int(input())
    A = [int(x)-1 for x in input().split()]
    B = [int(x) for x in input().split()]
    C = [int(x) for x in input().split()]
    ans = sum(B[a] for a in A)
    for a1, a2 in zip(A, A[1:]):
        if a1 + 1 == a2:
            ans += C[a1]
    print(ans)


if __name__ == '__main__':
    main()
