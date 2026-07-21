def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    sum = 0

    before = A[0]

    for ryouri in A:
        if before + 1 == ryouri:
            sum += B[ryouri - 1] + C[before - 1]
        else:
            sum += B[ryouri - 1]

        before = ryouri

    print(sum)


if __name__ == "__main__":
    main()
