import sys
input = sys.stdin.buffer.readline


n = int(input())
A = [int(i) for i in input().split()]

_min = 10**9 + 1
flag = False  # if minus integers is odd, flag is True
_sum = 0

for a in A:
    _sum += abs(a)
    _min = min(_min, abs(a))
    if a < 0:
        flag = not flag

if flag:
    _sum -= _min * 2
print(_sum)
