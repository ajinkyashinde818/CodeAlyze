import sys

sys.setrecursionlimit(10 ** 7)
f_inf = float('inf')
mod = 10 ** 9 + 7


def resolve():
    s = input()
    n = len(s)
    ss = "".join(s.replace("x", ""))
    if ss != ss[::-1]:
        print(-1)
        exit()

    res = 0
    left = 0
    right = n - 1
    while left <= right:
        if s[left] == s[right]:
            left += 1
            right -= 1
        else:
            if s[left] == "x":
                left += 1
            else:
                right -= 1
            res += 1
    print(res)


if __name__ == '__main__':
    resolve()
