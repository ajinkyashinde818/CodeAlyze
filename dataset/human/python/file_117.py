from collections import defaultdict
from string import ascii_uppercase
import sys, bisect, math
stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

R,G,B,N = read_int()

def solve():
    ans = 0

    for i in range(0, N + 1, R):
        res = i
        if res > N: continue
        for j in range(0, N + 1 - res, G):
            res = i + j
            if res <= N and (N - res) % B == 0:
                ans += 1
    return ans

if __name__ == "__main__":
    print(solve())
