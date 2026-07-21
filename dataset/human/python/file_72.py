from math import ceil


def main():
    r, g, b, n = map(int, input().split())
    answer = 0
    for i in range(n + 1):
        for j in range(n + 1 - i * r):
            left = n - i * r - j * g
            if left >= 0 and left % b == 0:
                answer += 1
    print(answer)


if __name__ == '__main__':
    main()
