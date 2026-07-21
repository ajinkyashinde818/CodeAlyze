def main():
    N = int(input())
    *A, = map(int, input().split())

    n_neg = 0
    near_zero = 10 ** 10
    for a in A:
        if a < 0:
            n_neg += 1
        near_zero = min(near_zero, abs(a))

    s = sum([abs(a) for a in A])
    if n_neg % 2 == 0:
        print(s)
    else:
        print(s - near_zero * 2)


main()
