import sys
import itertools


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    d, g = list(map(int, input().rstrip('\n').split()))
    pc = [[(i + 1) * 100, pc[0], pc[1]]for i, pc in enumerate(list(map(int, input().rstrip('\n').split())) for _ in range(d))]
    pc.sort(reverse=True)
    min_cnt = 10 ** 10
    for v in itertools.product([True, False], repeat=d):
        cnt = 0
        t = 0
        max_p = -1
        limit_c = -1
        for i, vv in enumerate(v):
            if vv:
                cnt += pc[i][1]
                t += pc[i][0] * pc[i][1] + pc[i][2]
            else:
                if max_p < pc[i][0]:
                    max_p = pc[i][0]
                    limit_c = pc[i][1]
        if t >= g:
            min_cnt = min(min_cnt, cnt)
        else:
            if 1 <= (g - t + max_p - 1) // max_p <= limit_c:
                min_cnt = min(min_cnt, cnt + (g - t + max_p - 1) // max_p)
    print(min_cnt)


if __name__ == '__main__':
    solve()
