import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    R, G, B, N = [int(x) for x in input().split()]

    ans = 0
    f = False
    for i in range(N + 1):
        if i * R > N:
            break
        for j in range(N + 1):
            if i * R + j * G > N:
                break

            if (N - (i * R + j * G)) % B == 0:
                ans += 1

    print(ans)



if __name__ == '__main__':
    main()
