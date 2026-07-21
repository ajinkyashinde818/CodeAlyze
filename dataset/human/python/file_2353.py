INF = 10 ** 9
import sys
sys.setrecursionlimit(100000000)
dy = (-1,0,1,0)
dx = (0,1,0,-1)
from  heapq import heappop,heapify,heappush
from bisect import bisect_left

def main():
    d,g = map(int,input().split())
    problems = [list(map(int,input().split())) for _ in range(d)]
    
    ans = INF
    for bit in range(1 << d):
        ret = 0
        tot = 0
        left = -1
        for i in range(d):
            if (bit>>i)&1:
                tot += (i + 1) * 100 * problems[i][0] + problems[i][1]
                ret += problems[i][0]
            else:
                left = i
        
        if tot >= g:
            ans = min(ans,ret)
            continue
        
        if tot + (left + 1) * 100 * (problems[left][0] - 1) >= g:
            tmp = (left + 1) * 100
            ret += (g - tot + tmp - 1)//tmp
            ans = min(ans,ret)

    print(ans)

if __name__ == '__main__':
    main()
