import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    N, K = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]

    v = set()

    c = 1
    cnt = 0
    while True:
        if c in v:
            break
        v.add(c)
        cnt += 1
        c = A[c - 1]
        if cnt == K:
            print(c)
            return
    K -= cnt

    syuki = []
    syuki.append(c)
    c = A[c - 1]
    while True:
        if c == syuki[0]:
            break
        syuki.append(c)
        c = A[c - 1]
    print(syuki[K % len(syuki)])

if __name__ == '__main__':
    main()
