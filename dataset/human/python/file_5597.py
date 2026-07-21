import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(500000)

s = read().decode("utf-8").rstrip()
l = 0
r = len(s) - 1

cnt = 0
while len(s) != 0:
    if s[0] == s[-1]:
        s = s[1:-1]
    elif s[0] == 'x':
        s += 'x'
        cnt += 1
    elif s[-1] == 'x':
        s = 'x' + s
        cnt += 1
    else:
        print(-1)
        sys.exit()

print(cnt)
