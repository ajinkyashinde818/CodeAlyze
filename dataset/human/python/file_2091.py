import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')


def main():
    N = in_n()
    S = in_s()

    mod = 10**9 + 7
    orda = ord('a')
    ordz = ord('z')
    ans = 1
    for c in range(orda, ordz + 1):
        ans *= (S.count(chr(c)) + 1)
        ans %= mod

    print(ans - 1)


if __name__ == '__main__':
    main()
