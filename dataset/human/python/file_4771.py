import sys

def main():
    input = sys.stdin.readline
    s = [str(c) for c in input().strip()]
    t = [str(c) for c in input().strip()]

    s = sorted(s)
    t = sorted(t)[::-1]

    S = ''
    for c in s:
        S += c
    T = ''
    for c in t:
        T += c

    if S < T:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()
