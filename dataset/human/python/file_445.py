import sys

def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))

    S = 0
    min_ = 10**9 + 1
    neg = 0
    for a in A:
        S += abs(a)
        min_ = min(min_, abs(a))

        if a < 0:
            neg += 1

    if neg % 2 == 0:
        return S
    else:
        return S - 2 * min_


if __name__ == '__main__':
    print(main())
