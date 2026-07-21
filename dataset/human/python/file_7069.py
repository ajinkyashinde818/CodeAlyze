import sys
import math
from collections import deque

if __name__ == "__main__":
    S = input()
    Q = int(input())
    mode = 0
    d = deque()
    for s in S:
        d.append(s)
    
    for i in range(Q):
        arr = list(input().split())
        if len(arr) == 1:
            mode ^= 1
        else:
            if arr[1] == '1':
                if mode == 0:
                    # print(i)
                    d.appendleft(arr[2])
                else:
                    d.append(arr[2])
            else:
                if mode == 0:
                    d.append(arr[2])
                else:
                    d.appendleft(arr[2])
        # print(mode, d);
    ans = ""
    while len(d):
        if mode == 0:
            ans += d.popleft()
        else:
            ans += d.pop()
    print(ans)
