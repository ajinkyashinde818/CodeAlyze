import sys
input = sys.stdin.readline
from collections import deque
def main():
    S = input().rstrip("\r\n")
    Q = int(input())
    d = deque(S)
    reverse = False
    for _ in range(Q):
        q = input().rstrip("\r\n")
        if q == "1":
            reverse = not reverse
        else:
            _, f, c = q.split()
            if (f == "1" and not reverse) or (f == "2" and reverse):
                d.appendleft(c)
            else:
                d.append(c)
    l = list(d)
    if reverse:l.reverse()
    print("".join(l))
if __name__ == "__main__":
    main()
