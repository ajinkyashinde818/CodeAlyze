import sys

INPUT = lambda: sys.stdin.readline().rstrip()
MAP = lambda: map(int, INPUT().split())

sys.setrecursionlimit(10 ** 9)


def main():
    N, K, S = MAP()

    ans = []
    for i in range(N):
        if i < K: ans.append(S)
        else:
            if S-1 >= 1: ans.append(S-1)
            else: ans.append(S+1)

    print(*ans)


if __name__ == '__main__':
    main()
