import sys
from collections import deque

input = sys.stdin.readline


def main():
    S = input().rstrip()
    Q = int(input())

    prefix = deque()
    surfix = deque()
    prefix_append = prefix.appendleft
    surfix_append = surfix.append
    is_reversed = False
    for _ in range(Q):
        q = input().split()
        if q[0] == "1":
            is_reversed = not is_reversed
        else:
            if q[1] == "1":
                if is_reversed:
                    surfix_append(q[2])
                else:
                    prefix_append(q[2])
            else:
                if is_reversed:
                    prefix_append(q[2])
                else:
                    surfix_append(q[2])

    ans = "".join(["".join(prefix), S, "".join(surfix)])
    if is_reversed:
        ans = ans[::-1]

    print(ans)


if __name__ == "__main__":
    main()
