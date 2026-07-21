import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

s = ns()
a = ["a", "b", "c"]
f = 0
g = 0
h = 0
for i in s:
    if i == "a":
        f += 1
    if i == "b":
        g += 1
    if i == "c":
        h += 1

if f == 1 and g == 1 and h == 1:
    print("Yes")
else:
    print("No")
