def p_d():
    n = int(input())
    *a, = map(int, input().split())
    *b, = filter(lambda x: x <= 0, a)
    *c, = map(abs, a)
    if len(b) & 1 == 0:
        print(sum(c))
    else:
        print(sum(c) - 2 * sorted(c)[0])


if __name__ == '__main__':
    p_d()
