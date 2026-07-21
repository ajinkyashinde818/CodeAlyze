from collections import deque
s = deque(i for i in input())
n = int(input())
l = [[i for i in input().split()] for _ in range(n)]

front = True

for i in l:
    if i[0] == '1':
        front = not front
    else:
        if front ^ (int(i[1]) == 1):
            s.append(i[2])
        else:
            s.appendleft(i[2])
            
ans = ''.join(s)

if front:
    print(ans)
else:
    ans = ans[::-1]
    print(ans)
