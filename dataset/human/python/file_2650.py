import sys
from itertools import permutations

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    D, G = map(int, input().split())
    PC = [(0, 0, 0)]
    for i in range(1, D + 1):
        p, c = map(int, input().split())
        PC.append((i, p, c))
    perms = permutations(range(1, D + 1))

    ans = INF
    for p in perms:
        tmp = 0
        cnt = 0
        for idx in p:
            i, p, c = PC[idx]
            if tmp + 100 * i * p >= G:
                cnt += (G - tmp + 100 * i - 1) // (100 * i)
                break
            elif tmp + 100 * i * p + c >= G:
                cnt += p
                break
            else:
                tmp += 100 * i * p + c
                cnt += p

        if cnt < ans:
            ans = cnt

    print(ans)


if __name__ == "__main__":
    main()
