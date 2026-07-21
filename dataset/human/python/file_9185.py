import sys
from collections import deque

def main():
    input = sys.stdin.readline
    S = str(input().strip())
    stock = ['dream', 'dreamer', 'erase', 'eraser']

    q = deque()
    q.append(S)
    while len(q) > 0:
        s = q.popleft()
        if len(s) == 0:
            return 'YES'

        if s[:5] in stock:
            q.append(s[5:])
        if s[:6] in stock:
            q.append(s[6:])
        if s[:7] in stock:
            q.append(s[7:])

    return 'NO'


if __name__ == '__main__':
    print(main())
