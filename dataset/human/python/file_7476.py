from collections import deque
import sys
input = sys.stdin.readline
sys.setrecursionlimit(4100000)


def main():
    a = deque(input())
    a.pop()

    a_append = a.append
    a_appendleft = a.appendleft

    Q = int(input())
    count = 0
    for _ in range(Q):
        q = list(input().split())
        if q[0] == "1":
            count += 1
        else:
            if count % 2 == 0:
                if q[1] == "1":
                    a_appendleft(q[2])
                else:
                    a_append(q[2])
            else:
                if q[1] == "1":
                    a_append(q[2])
                else:
                    a_appendleft(q[2])

    b = list(a)
    if count % 2 != 0:
        b.reverse()
    print("".join(b))


if __name__ == '__main__':
    main()
