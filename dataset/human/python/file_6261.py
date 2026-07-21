import sys

stdin = sys.stdin


def ni(): return int(ns())


def na(): return list(map(int, stdin.readline().split()))


def ns(): return stdin.readline().rstrip()  # ignore trailing spaces


N = ns()

ans = [0, 1000000000]
kuri = [0, 0]
five = 0
for n in N[::-1]:
    n = int(n)
    # print(ans)
    ans_old = [ans[0], ans[1]]
    ans[0] = min(ans_old[0] + n, ans_old[1] + n + 1)
    ans[1] = min(ans_old[0] + 10 - n, ans_old[1] + 9 - n)
print(min(ans[0], ans[1] + 1))
