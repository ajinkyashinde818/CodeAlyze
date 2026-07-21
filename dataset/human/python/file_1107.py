import sys
from bisect import bisect_right, bisect_left
from collections import Counter


def main():
    input = sys.stdin.buffer.readline
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    cnt = Counter(a + b)
    e, num = cnt.most_common(1)[0]
    if num > n:
        print("No")
    else:
        step = 0
        for e in set(a) & set(b):
            s = bisect_right(a, e) - bisect_left(b, e)
            step = max(step, s)
        ans = [0] * n
        for i in range(n):
            ans[i] = b[(i - step) % n]
        print("Yes")
        print(*ans)


if __name__ == "__main__":
    main()
