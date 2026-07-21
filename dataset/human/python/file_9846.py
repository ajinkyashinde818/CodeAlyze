import sys
read = sys.stdin.read
readlines = sys.stdin.readlines
import numpy as np
def main():
    n, k, *a = map(int, read().split())

    cur = 1
    path = [0] * (n + 1)
    while k:
        if path[cur]:
            break
        else:
            path[cur] = k
            cur = a[cur - 1]
            k -= 1
            if k == 0:
                print(cur)
                sys.exit()
    cycle = path[cur] - k
    k = k % cycle
    while k:
        cur = a[cur - 1]
        k -= 1
    print(cur)

if __name__ == '__main__':
    main()
