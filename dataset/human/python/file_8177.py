import sys

input = sys.stdin.readline


def ii():
    return int(input())


def il():
    return list(map(int, input().split()))


K, S = il()
c = 0
for x in range(K + 1):
    for y in range(K + 1):
        if 0 <= (S - (x + y)) <= K:
            c += 1
print(c)
