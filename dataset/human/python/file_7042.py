import sys
from collections import deque

def main():
    input = sys.stdin.readline

    s = input()[:-1]
    q = int(input())
    tmp = [input().split() for _ in range(q)]

    flag = 0
    ans = deque([s])
    for t in tmp:
        if len(t) == 1:
            flag = ~flag 
        else:
            f = int(t[1])
            c = t[2]
            if (f == 1 and flag == 0) or (f ==2 and flag == -1):
                ans.appendleft(c)
            else:
                ans.append(c)
    if flag == 0:
        print(''.join(ans))
    else:
        print(''.join(ans)[::-1])

if __name__ == '__main__':
    main()
