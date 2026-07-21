import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)


def is_integer_num(n):
    if isinstance(n, int):
        return True
    if isinstance(n, float):
        return n.is_integer()
    return False


def main():
    R, G, B, N = map(float, input().split())
    cnt = 0

    for r in range(0, 3000 // int(R) + 1):
        for g in range(0, 3000 // int(G) + 1):
            b = (N - R * r - G * g) / B
            # print(b)
            if b >= 0 and is_integer_num(b):
                # print(r, g, b)
                cnt += 1

    print(cnt)


if __name__ == "__main__":
    main()
