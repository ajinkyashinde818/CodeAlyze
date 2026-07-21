import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)
 
l= int(readline())
if l% 2 == 1:
    print(0)
else:
    l //= 2
    ans = 0
    while l:
        l //= 5
        ans += l
    print(ans)
