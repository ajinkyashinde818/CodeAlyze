import sys


def input(): return sys.stdin.readline().strip()
def I(): return int(input())
def LI(): return list(map(int, input().split()))
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def S(): return input()
def LS(): return input().split()


s = S()
# 後ろから見る
s = s[::-1]
t = ''
ans = 'YES'
i = 0
while True:
    # print(f'{i=}')
    # print(f'{s[i:]=}')
    if s[i: i + 7] == 'dreamer'[::-1]:
        i += 7
    elif s[i: i + 6] == 'eraser'[::-1]:
        i += 6
    elif s[i: i + 5] == 'dream'[::-1]:
        i += 5
    elif s[i: i + 5] == 'erase'[::-1]:
        i += 5
    elif i >= len(s):
        break
    else:
        ans = 'NO'
        break
print(ans)
