import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline


def main():
    N, M = map(int, readline().split())
    m = map(int, read().split())
    AB = list(zip(m, m))

    p1 = []
    p2 = []
    for a, b in AB:
        if a == 1:
            p1.append(b)
        if b == N:
            p2.append(a)

    if len(list(set(p1) & set(p2))) >= 1:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')


main()
