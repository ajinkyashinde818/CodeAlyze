import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)
 
nu = int(readline())
if nu % 2 == 1:
    print(0)
else:
    nu //= 2
    answ = 0
    while nu:
        nu //= 5
        answ += nu
    print(answ)
