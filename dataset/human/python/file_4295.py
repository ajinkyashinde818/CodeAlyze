import sys
import math
from collections import defaultdict
def input(): return sys.stdin.readline().rstrip()

def main():
    N = int(input())

    ans = 0
    MAX_N = math.ceil(math.sqrt(N)) + 1

    div = defaultdict(int)
    for i in range(2, MAX_N):
        while N % i == 0:
            N //= i
            div[i] += 1
            if N == 1:
                break
    for i, v in div.items():
        key = 1
        while True:
            v -= key
            ans += 1
            if v <= key:
                break
            key += 1

    if N > 1:
        ans += 1
    print(ans)

if __name__ == '__main__':
    main()
