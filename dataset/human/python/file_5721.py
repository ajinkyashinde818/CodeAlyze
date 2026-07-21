import sys

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    S = input()
    noX = S.replace('x','')
    if list(noX) == list(reversed(noX)):
        l = 0
        r = len(S)-1
        count = 0
        while l<r:
            if S[l] == S[r]:
                l += 1
                r -= 1
            else:
                if S[l] == 'x':
                    count += 1
                    l += 1
                else:
                    count += 1
                    r -= 1
        print(count)
    else:
        print(-1)


if __name__ == '__main__':
    main()
