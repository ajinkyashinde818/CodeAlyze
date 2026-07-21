from collections import defaultdict
from collections import deque
from string import ascii_uppercase
import sys, bisect, math, heapq

stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

S = read_str()
Q = read_int()[0]
Query = [list(read_str().split()) for _ in range(Q)]

d = deque([S])
# rd = deque([S])
def solve():
    reverse = False
    for q in Query:
        if q[0] == '1':
            reverse = not reverse
        else:
            if reverse:
                if q[1] == '1':
                    # rd.appendleft(q[2])
                    d.append(q[2])
                else:
                    d.appendleft(q[2])
                    # rd.append(q[2])
            else:
                if q[1] == '1':
                    d.appendleft(q[2])
                    # rd.append(q[2])
                else:
                    # rd.appendleft(q[2])
                    d.append(q[2])
        # print(d, rd, reverse)
    ans = ''
    if reverse:
        ans = ''.join(list(d))[::-1]
    else:
        ans = ''.join(list(d))
    return ans

if __name__ == "__main__":
    print(solve())
