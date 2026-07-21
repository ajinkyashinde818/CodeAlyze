import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

n = int(read())
if n % 2 == 1:
    print(0)
    exit()
cnt = 0
n //= 2
while n:
    n //= 5
    cnt += n
print(cnt)
