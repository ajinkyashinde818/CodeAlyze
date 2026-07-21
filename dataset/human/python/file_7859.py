import sys
input = sys.stdin.readline


def main():
    N, K, S = [int(x) for x in input().split()]

    ans = []
    for i in range(K):
        ans.append(S)
    for i in range(N - K):
        if S == 10 ** 9:
            ans.append(10 ** 9 - 1)
        else:
            ans.append(10 ** 9)

    print(*ans)



if __name__ == '__main__':
    main()
