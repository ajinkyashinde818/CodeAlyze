import sys
input = sys.stdin.readline


def main():
    R, G, B, N = [int(ele) for ele in input().split()]
    ans = 0
    for i in range(N+1):
        tmp = N - i*R

        for j in range(N+1):
            tmp2 = tmp - j*G
            if tmp2 < 0:
                break
            if tmp2 % B == 0:
                ans += 1

    print(ans)


if __name__ == "__main__":
    main()
