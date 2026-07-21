from collections import deque

s = input()
q = int(input())

que = deque(s)
rev = 1
for qi in range(q):
    tmp = input()
    if tmp[0] == '1':
        rev *= -1
    if tmp[0] == '2':
        _, f, c = tmp.split()
        fi = 2 * (int(f) - 1) - 1
        if fi * rev == 1:
            que.append(c)
        else:
            que.appendleft(c)
lque = list(que)

if rev == 1:
    print(''.join(map(str, lque)))
    exit()

ans = ''
for i in range(len(lque)):
    ans += lque.pop()
print(ans)
