import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')


def main():
    S = in_s()
    S = S.replace('eraser', '')
    S = S.replace('erase', '')
    S = S.replace('dreamer', '')
    S = S.replace('dream', '')

    if len(S) == 0:
        ans = 'YES'
    else:
        ans = 'NO'
    print(ans)


if __name__ == '__main__':
    main()
