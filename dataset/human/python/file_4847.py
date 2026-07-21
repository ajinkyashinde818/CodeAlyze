import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

s = list(readline().rstrip().decode())
t = list(readline().rstrip().decode())
s.sort()
t.sort(reverse=True)
for ss, tt in zip(s, t):
    if ss < tt:
        print('Yes')
        exit()
    if ss > tt:
        print('No')
        exit()
if len(s) < len(t):
    print('Yes')
else:
    print('No')
