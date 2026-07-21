from collections import deque
import sys
input = sys.stdin.readline

def main():
    S = list(input().strip())
    Q = int(input())

    d = deque(S)
    mode = True

    for _ in range(Q):
        query = input().split()

        if query[0] == "1":
            mode = not mode
        elif query[0] == "2":
            F, C = query[1], query[2]
            if F == "1":
                if mode:
                    d.appendleft(C)
                else:
                    d.append(C)
            elif F == "2":
                if mode:
                    d.append(C)
                else:
                    d.appendleft(C)

    s = list(d)
    if not mode:
        s = s[::-1]

    print(''.join(s))

if __name__ == "__main__":
    main()
