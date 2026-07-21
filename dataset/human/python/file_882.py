import sys
import math
from collections import deque
from collections import defaultdict

def main():
    n,r = list(map(int,sys.stdin.readline().split()))
    if n>=10:
        ans = r
    else: ans = 100*(10-n)+r
    print(ans)
if __name__ == "__main__":
    main()
