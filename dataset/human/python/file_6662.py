import sys
import collections

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    S = input().strip()
    Q = int(input())

    rev = 0
    sdeq = collections.deque(list(S))

    for i in range(Q):
        A = [x for x in input().split()]
        if len(A) == 1:
            rev = (rev + 1) % 2
        else:
            f = int(A[1])
            c = A[2]
            if f == 1:
                if rev == 0:
                    sdeq.appendleft(c)
                else:
                    sdeq.append(c)
            else:
                if rev == 0:
                    sdeq.append(c)
                else:
                    sdeq.appendleft(c)

    if rev == 0:
        print("".join(list(sdeq)))
    else:
        print("".join(list(sdeq)[::-1]))
    print()



if __name__ == '__main__':
    main()
