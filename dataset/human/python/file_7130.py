from collections import deque
import sys

def main():
    s = sys.stdin.readline().strip()
    qn = int(sys.stdin.readline().strip())
    qs = [input().split() for _ in range(qn)]

    s = deque(s)
    r = 1
    for q in qs:
        if len(q) == 1:
            r = r * -1

        else:
            if q[1] == '1':
                if r == 1:
                    s.appendleft(q[2])
                else:
                    s.append(q[2])
            else:
                if r == 1:
                    s.append(q[2])
                else:
                    s.appendleft(q[2])

    if r == 1:
        print(''.join(s))
    else:
        s.reverse()
        print(''.join(s))

if __name__ == "__main__":
    main()
