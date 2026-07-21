import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
if N % 2 == 1:
    print(0)
    sys.exit()
ans = 0
i = 1
while True:
    div = 5 ** i
    cnt = N // div
    cnt //= 2
    if cnt == 0:
        break
    ans += cnt
    i += 1
print(ans)
