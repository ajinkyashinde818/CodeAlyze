import collections


def main():
    cnt = 0
    R, G, B, N = list(map(int, input().split()))
    for r in range(N // R + 1):
        for g in range((N - r * R)//G + 1):
            k = N - r * R - g * G
            if k % B == 0:
                cnt += 1
    print(cnt)


if __name__ == '__main__':
    main()
