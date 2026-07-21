import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

s = input()
size = len(s)
cnt = size
flag = False
for i in range(size):
    if s[cnt - 1] == 'r':
        if cnt >= 7:
            if s[cnt - 7:cnt] == 'dreamer':
                cnt -= 7
            elif s[cnt - 6:cnt] == 'eraser':
                cnt -= 6
            else:
                flag = True
                break
        elif cnt >= 6:
            if s[cnt - 6:cnt] == 'eraser':
                cnt -= 6
            else:
                flag = True
                break
        else:
            flag = True
            break
    elif s[cnt - 1] == 'e' and cnt >= 5:
        if s[cnt - 5:cnt] == 'erase':
            cnt -= 5
        else:
            flag = True
            break
    elif s[cnt - 1] == 'm' and cnt >= 5:
        if s[cnt - 5:cnt] == 'dream':
            cnt -= 5
        else:
            flag = True
            break
    else:
        flag = True
        break
    if cnt == 0:
        break
    elif cnt < 0:
        flag = True
        break
if flag:
    print('NO')
else:
    print('YES')
