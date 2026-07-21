import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

n = ns()
flag = 0
for i in n:
    if i == "9":
        flag = 1
if flag == 1:
    print("Yes")
else:
    print("No")
