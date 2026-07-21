import sys
import itertools
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')


def main():

    s = in_s()

    if s == s[::-1]:
        print(0)
        exit()

    t = s.replace('x', '')
    if t != t[::-1]:
        print(-1)
        exit()

    f = (s[0] == 'x')
    xnum = []
    count = 0
    s = s + 'a'
    N = len(s)

    for i in range(N):
        if s[i] == 'x':
            if f:
                count += 1
            else:
                count = 1
            f = True
        else:
            if f:
                xnum.append(count)
                count = 0
            else:
                xnum.append(0)
            f = False

    ans = 0
    xn = len(xnum)
    for i in range(xn // 2):
        ans += abs(xnum[i] - xnum[xn - 1 - i])

    print(ans)


if __name__ == '__main__':
    main()
