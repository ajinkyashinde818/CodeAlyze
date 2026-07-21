def main():
    N = int(input())
    A = list(map(int, input().split(' ')))
    abs_A = list(map(abs, A))
    neg_cnt = sum([1 if a < 0 else 0 for a in A])
    if neg_cnt % 2 == 0:
        print(sum(abs_A))
    else:
        abs_A.sort()
        print(sum(abs_A) - 2 * abs_A[0])


if __name__ == '__main__':
    main()
