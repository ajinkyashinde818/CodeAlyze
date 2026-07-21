import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n = list(map(int, list(readline().rstrip().decode())[::-1]))
a = 0
b = 10000
for x in n:
    memo = min(a + x, b + x)
    b = min(a + 11 - x, b + 9 - x)
    a = memo
print(min(a, b))
