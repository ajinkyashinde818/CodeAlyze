import sys
from collections import deque


def main():
    s = sys.stdin.readline().strip()
    q = int(sys.stdin.readline().strip())
    r = 0
    head = []
    bottom = []
    do_reverse = False
    for _ in range(q):
        command = sys.stdin.readline().strip().split(" ")
        # if command[0] == "1":
        #     s = s[::-1]
        # else:
        #     if command[1] == "1":
        #         s = command[2] + s
        #     else:
        #         s = s + command[2]
        if command[0] == "1":
            do_reverse = not do_reverse
            r += 1
        else:
            position_head = command[1] == "1"
            if do_reverse:
                position_head = not position_head
            if position_head:
                head.append(command[2])
            else:
                bottom.append(command[2])
    if r % 2 == 0:
        print("".join(head[::-1]) + s + "".join(bottom))
    else:
        print("".join(bottom[::-1]) + s[::-1] + "".join(head))


if __name__ == '__main__':
    main()
