import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)
 
n = int(readline())
if n % 2 == 1:
    print(0)
else:
    n //= 2
    answ = 0
    while n:
        n //= 5
        answ += n
    print(answ)
