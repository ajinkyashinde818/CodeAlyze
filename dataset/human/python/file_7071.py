import sys
import os


def main():
    if os.getenv("LOCAL"):
        sys.stdin = open("input.txt", "r")

    ret = sys.stdin.readline().rstrip()
    Q = int(sys.stdin.readline().rstrip())
    m = ""
    u = ""
    r = 0
    for q in range(Q):
        line = sys.stdin.readline().split()
        if line[0] == '1':
            m, u = u, m
            r ^= 1
        elif line[0] == '2' and line[1] == '1':
            m += line[2]
        else:
            u += line[2]

    if r == 0:
        print(m[::-1] + ret[::1] + u)
    else:
        print(m[::-1] + ret[::-1] + u)


if __name__ == '__main__':
    main()
