def main():
    N = int(input())
    A = list(map(int, input().split()))
    negatives = 0
    zeros = 0
    min_abs = 10**9 + 1
    for a in A:
        if a < 0:
            negatives += 1
        if a == 0:
            zeros += 1
        min_abs = min(min_abs, abs(a))
    ans = sum(map(abs, A))
    if negatives % 2 == 0 or zeros != 0:
        print(ans)
        return

    ans -= 2*min_abs
    print(ans)

if __name__ == '__main__':
    main()
