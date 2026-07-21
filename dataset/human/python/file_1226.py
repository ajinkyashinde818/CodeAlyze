def main():
    N = int(input())
    *A, = map(int, input().split())

    def accumulate(a):
        s = 0
        for x in a:
            s += x
            yield s

    *acc, = accumulate(A)
    acc.pop()

    tot = sum(A)

    ans = -1
    for x in acc:
        if ans > (abs_ := abs(tot - x - x)) or not (~ans):
            ans = abs_

    print(ans)


if __name__ == '__main__':
    main()
