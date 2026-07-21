def main():
    _ = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    ret = sum(B)
    for i, i1 in zip(A, A[1:]):
        if i1 == i + 1:
            ret += C[i - 1]
    print(ret)


main()
