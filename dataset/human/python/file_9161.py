import sys


def input():
    return sys.stdin.readline()[:-1]


def ii(t: type = int):
    return t(input())


def il(t: type = int):
    return list(map(t, input().split()))


def imi(N: int, t: type = int):
    return [ii(t) for _ in range(N)]


def iml(N: int, t: type = int):
    return [il(t) for _ in range(N)]


print(
    "NO"
    if ii(str)
    .replace("eraser", "")
    .replace("erase", "")
    .replace("dreamer", "")
    .replace("dream", "")
    else "YES"
)
