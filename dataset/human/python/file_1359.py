def main():
    N = int(input())
    A = list(map(int, input().split()))
    sum_sunuke = 0
    sum_arai = sum(A)
    diffs = []
    for i in range(N - 1):
        sum_sunuke += A[i]
        sum_arai -= A[i]
        diffs.append(abs(sum_sunuke - sum_arai))
    print(min(diffs))


if __name__ == '__main__':
    main()
