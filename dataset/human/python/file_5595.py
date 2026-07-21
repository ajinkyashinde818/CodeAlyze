import sys


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(20000000)

MOD = 10 ** 9 + 7
INF = float("inf")


def main():
    S = input()
    answer = 0
    while S:
        if S[0] == S[-1]:
            S = S[1:-1]
        elif S[0] == "x":
            S = S + "x"
            answer += 1
        elif S[-1] == "x":
            S = "x" + S
            answer += 1
        else:
            print(-1)
            return
    print(answer)


if __name__ == "__main__":
    main()
