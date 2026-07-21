INF = 10 ** 10
import sys
sys.setrecursionlimit(100000000)
dy = (-1,0,1,0)
dx = (0,1,0,-1)
from  collections import deque

def main():
    k,s = map(int,input().split())
    ans = 0
    for i in range(k + 1):
        for j in range(k + 1):
            if 0 <= s - i - j <= k:
                ans += 1
    print(ans)
if __name__ == '__main__':
    main()
