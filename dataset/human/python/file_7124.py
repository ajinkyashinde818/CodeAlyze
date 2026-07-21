import sys
import collections


def solve():
    input = sys.stdin.readline
    mod = 10 ** 9 + 7
    s = str(input().rstrip('\n'))
    s = collections.deque(s)
    q = int(input().rstrip('\n'))
    r = False
    for _ in range(q):
        tfc = list(map(str, str(input().rstrip('\n')).split()))
        if tfc[0] == "1":
            r = not r
        else:
            if not r:
                if tfc[1] == "1":
                    s.appendleft(tfc[2])
                else:
                    s.append(tfc[2])
            else:
                if tfc[1] == "1":
                    s.append(tfc[2])
                else:
                    s.appendleft(tfc[2])
    print("".join(list(s)) if not r else "".join(reversed(s)))


if __name__ == '__main__':
    solve()
