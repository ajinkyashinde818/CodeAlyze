import sys
input = sys.stdin.readline


def main():
    r, g, b, n = map(int, input().split())
    ans = 0
    for i in range(n//r + 1):
        for j in range(n//g + 1):
            residue = n - i*r - g*j
            if residue >= 0 and residue % b == 0:
                ans += 1

    print(ans)


if __name__ == "__main__":
    main()
