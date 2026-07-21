import math
from collections import deque


def main():
    n, k, s = map(int, input().split())
    ans = []

    for i in range(n):
        if i < k:
            ans.append(s)
        else:
            if k == n:
                ans.append(s)
            else:
                if s == 2 or s == 1:
                    ans.append(3)
                else:
                    ans.append(s-1)

    # if s % 2 == 0:
    #     for i in range(k + 1):
    #         ans.append(s // 2)
    #     for i in range(n - k - 1):
    #         if s == 2:
    #             ans.append(3)
    #         else:
    #             ans.append(s-1)
    # else:
    #     for i in range(k):
    #         ans.append(s)
    #     for i in range(n - k):
    #         ans.append(s + 1)
    print(" ".join(map(str, ans)))


if __name__ == "__main__":
    main()
