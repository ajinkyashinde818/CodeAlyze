import sys
import math


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(20000000)

MOD = 10 ** 9 + 7
INF = float("inf")


def main():
    D, G = map(int, input().split())
    problems = [list(map(int, input().split())) for _ in range(D)]
    answer = INF
    for i in range(2 ** D):
        ans = 0
        point = 0
        for j in range(D):
            if (i >> j) & 1:
                point += problems[j][0] * 100 * (j + 1) + problems[j][1]
                ans += problems[j][0]
        j = D - 1

        while point < G and j >= 0:
            if not (i >> j) & 1:
                p = math.ceil((G - point) / (100 * (j + 1)))
                if problems[j][0] >= p:
                    point += p * 100 * (j + 1)
                    ans += p
                    j = 0
                else:
                    j = 0
            j -= 1
        if answer > ans and point >= G:
            answer = ans
    print(answer)


if __name__ == "__main__":
    main()
