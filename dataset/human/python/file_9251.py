import sys
sys.setrecursionlimit(10000000)
x = input()
n = len(x)
ans = "NO"

def f(i):
    if n==i:
        global ans
        ans = "YES"
    else:
        if x[i:i+5] == "dream":
            f(i+5)
        if x[i:i+7] == "dreamer":
            f(i+7)
        if x[i:i+5] == "erase":
            f(i+5)
        if x[i:i+6] == "eraser":
            f(i+6)
f(0)
print(ans)
