import math


def main():
    N = int(input())

    if N == 0 or N == 1:
        ans = 0

    elif N % 2 == 0:
        B = N // 2
        n = math.floor(math.log(B) / math.log(5))

        ans = 0
        for i in range(1, n + 1):
            ans += B // (5**i)

    else:
        ans = 0

    print(int(ans))


main()
