import sys

stdin = sys.stdin

ns = lambda: stdin.readline().rstrip()
ni = lambda: int(stdin.readline().rstrip())
nm = lambda: map(int, stdin.readline().split())
nl = lambda: list(map(int, stdin.readline().split()))

s = input()
q = ni()
f = 0
top = ''
bot = ''
for _ in range(q):
    w = input().split()
    if w[0] == '1':
        f ^= 1
        top,bot = bot,top
    elif w[1] == '1':
        top += w[2]
    else:
        bot += w[2]
print(top[::-1] + s[::1-f*2] + bot)
