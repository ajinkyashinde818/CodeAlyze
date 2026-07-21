import sys

stdin = sys.stdin
def ns(): return stdin.readline().rstrip()
def ni(): return int(stdin.readline().rstrip())
def nm(): return map(int, stdin.readline().split())
def nl(): return list(map(int, stdin.readline().split()))


def main():
    r, g, b, n = nm()
    ans = 0
    for i in range(n + 1):
        if n - i * r < 0:
            break
        for j in range(n + 1):
            num = n - r * i - g * j
            if num < 0:
                break
            if (num > 0 and num % b == 0) or num == 0:
                ans += 1
    print(ans)


if __name__ == '__main__':
    main()
