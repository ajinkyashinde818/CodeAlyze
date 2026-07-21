import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    s = input()
    t = ""

    for c in s:
        if c != "x":
            t += c

    lt = len(t)
    lh = lt // 2
    tf = t[:lh]
    ts = t[lt-lh:][::-1]

    if tf == ts:
        cnt_end = lh + 1

        cnt = 0
        xf = []
        cur = 0
        for c in s:
            if c != "x":
                xf.append(cur)
                cur = 0
                cnt += 1
                if cnt == cnt_end:
                    break
            else:
                cur += 1

        cnt = 0
        xs = []
        cur = 0
        for c in s[::-1]:
            if c != "x":
                xs.append(cur)
                cur = 0
                cnt += 1
                if cnt == cnt_end:
                    break
            else:
                cur += 1

        ans = 0
        for x1, x2 in zip(xf, xs):
            ans += abs(x1 - x2)

        print(ans)
    else:
        print(-1)


if __name__ == '__main__':
    main()
