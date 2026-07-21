import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    n = int(input())
    A = list(map(int, input().split()))
    total = 0
    mi = f_inf
    cnt_minus = 0
    for a in A:
        if a < 0:
            cnt_minus += 1
        if mi > abs(a):
            mi = abs(a)
        total += abs(a)
    print(total if cnt_minus % 2 == 0 else total - mi * 2)


if __name__ == '__main__':
    resolve()
