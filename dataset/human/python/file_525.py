import sys


def parse(file):
    n = int(file.readline().strip())
    nums = map(int, file.readline().split())
    return n, nums


def main(n, nums):
    minimum_abs = 1e20
    negatives = 0
    ans = 0

    for num in nums:
        if num < 0:
            a = - num
            negatives += 1
        else:
            a = num

        if a < minimum_abs:
            minimum_abs = a
        ans += a

    if negatives % 2 == 1:
        ans -= (minimum_abs * 2)

    return ans


if __name__ == '__main__':
    print(main(*parse(sys.stdin)))
