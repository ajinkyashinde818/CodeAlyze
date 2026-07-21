import sys
si = sys.stdin.readline


def main():
    [n, k] = [int(e) for e in si().split()]
    trace = dict()
    for i in range(1, n+1):
        trace[i] = 0

    l = [int(e) for e in si().split()]
    i, cnt = 1, 0
    while k > 0:
        k -= 1
        cnt += 1
        i = l[i-1]
        if i == 1 or trace[i] != 0:
            cy = cnt-trace[i]
            k %= cy
            break
        trace[i] = cnt
    while k > 0:
        i = l[i-1]
        k -= 1
    print(i)


if __name__ == '__main__':
    main()
