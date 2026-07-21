import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

x,y = ns().split()
hx = {"A":1, "B":2, "C":3, "D":4, "E":5, "F":6}

if hx[x] > hx[y]:
    print(">")
elif hx[x] < hx[y]:
    print("<")
else:
    print("=")
