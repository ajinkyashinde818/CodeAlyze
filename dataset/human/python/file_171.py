import os, sys, re, math

r,g,b,n = input().split(' ')
r,g,b,n = int(r), int(g), int(b), int(n)

ret = 0
ri = 0
while (ri * r <= n):
    rg = 0
    while (rg * g <= n - ri * r):
        if ((n - ri * r - rg * g) % b == 0):
            ret += 1
        rg += 1
    ri += 1

print(ret)
