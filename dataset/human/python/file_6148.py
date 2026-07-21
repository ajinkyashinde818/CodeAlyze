import sys

sys.setrecursionlimit(10 ** 5 + 10)


def input(): return sys.stdin.readline().strip()


def resolve():
    a, b, c = map(int, input().split())
    cnt = 0
    if a+b-1>c:
        print(b+c)
    else:
        c -= b
        cnt += b * 2

        if a < c:
            cnt += a + 1
        elif a == c:
            cnt += a
        else:
            if c > 0:
                cnt += c + 1

        print(cnt)



resolve()
