def main():
    N = int(input())
    A = [int(a) for a in input().rstrip().split()]
    sum_A = sum(A)
    sum_N = (N + 1) * N // 2
    if sum_A % sum_N:
        print('NO')
        return

    ope_num = sum_A // sum_N
    diffs = [r - l - ope_num for l, r in zip(A[:-1], A[1:])] + [A[0] - A[-1] - ope_num]
    if all([d % N == 0 and d <= 0 for d in diffs]):
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    main()
