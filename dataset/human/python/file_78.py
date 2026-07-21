import sys
input = sys.stdin.readline


def main():
    R, G, B, N = map(int, input().split())
    ans = 0
    for r in range(N+1):
        if r*R > N:
            continue
        for g in range(N+1):
            if r*R + g*G > N:
                continue
            if (N - r*R - g*G) % B == 0:
                ans += 1
    print(ans)


if __name__ == '__main__':
    main()
